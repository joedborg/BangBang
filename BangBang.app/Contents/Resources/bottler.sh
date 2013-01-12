#!/bin/sh



##########                         Debug Info                         ##########
################################################################################
WINE_VERSION=$("$WINEPATH/wine" --version |sed 's/wine-//')

echo "###BOTTLING### Gathering debug Info..."
echo ""
echo "Versions"
echo "OS...........................: "$OSTYPE
echo "Wine.........................: "$WINE_VERSION
echo "WineBottler..................: "$(pl < "../../Info.plist" | grep CFBundleVersion | sed 's/    CFBundleVersion = "//g' | sed 's/";//g')
echo ""
echo "Environment"
echo "PWD..........................: '"$(PWD)"'"
echo "PATH.........................: $PATH"
echo "WINEPATH.....................: $WINEPATH"
echo "LD_LIBRARY_PATH..............: $LD_LIBRARY_PATH"
echo "DYLD_FALLBACK_LIBRARY_PATH...: $DYLD_FALLBACK_LIBRARY_PATH"
echo "FONTCONFIG_FILE..............: $FONTCONFIG_FILE"
echo "DIPSPLAY.....................: $DISPLAY"
echo "SILENT.......................: $SILENT"
echo "http_proxy...................: $http_proxy"
echo "https_proxy..................: $https_proxy"
echo "ftp_proxy....................: $ftp_proxy"
echo "socks5_proxy.................: $socks5_proxy"
echo ""
/usr/sbin/system_profiler SPHardwareDataType
sleep 1



##########        Some export because I had troubles with paths        #########
################################################################################
export PATH="$BUNDLERESOURCEPATH":"$BUNDLERESOURCEPATH/bin":"$WINEPATH":$PATH
export WINE="$WINEPATH/wine"
export WINEPREFIX=$BOTTLE/Contents/Resources
export WINESERVER="$WINEPATH/wineserver"
export USERNAME="$USER"
#export LANG=fr.UTF-8
#export LC_CTYPE=fr_FR.UTF-8



##########              MULTIINSTANCE AND NOSPACE SUPPORT              #########
################################################################################
# - sometime people try to run multiple instances of winetricks, so we run them in separated places, so that we can tidy up afterwards
# - winetricks is often not safe for paths with spaces, so we link everithing to save paths)
export NOSPACE_PATH="/private/tmp/winebottler/"$(date +%s)
mkdir -p "$NOSPACE_PATH"


##########                       chatch errors                        ##########
################################################################################
winebottlerTry () {
#    "$@" &> /dev/null
    log=$("$@")
    status=$?
    if test $status -ne 0
    then
        rm -rf "$NOSPACE_PATH"
		echo "### LOG ### Command '$@' returned status $status."
		echo ""
		echo $log
		echo ""
        echo "###ERROR### Command '$@' returned status $status."
    fi
}
export -f winebottlerTry



##########           chatch errors of msi installer                   ##########
################################################################################
winebottlerTryMsi () {
    log=$("$@")
    status=$?
	#support ERROR_SUCCESS, ERROR_SUCCESS_REBOOT_INITIATED and ERROR_SUCCESS_REBOOT_REQUIRED
    if test $status -ne 0
		then
		if test $status -ne 1641
			then
			if test $status -ne 3010
			then
				echo "###ERROR### Command '$@' returned status $status."
				echo $log
			fi
		fi
	fi
}
export -f winebottlerTry



##########                  support for native dlls                   ##########
################################################################################
winebottlerOverrideDlls() {
    mode=$1
    shift
#    echo Using $mode override for following DLLs: $@
    cat > /tmp/override-dll.reg <<_EOF_
REGEDIT4

[HKEY_CURRENT_USER\Software\Wine\DllOverrides]
_EOF_
    while test "$1" != ""
    do
        case "$1" in
        comctl32)
           rm -rf "$WINDIR"/winsxs/manifests/x86_microsoft.windows.common-controls_6595b64144ccf1df_6.0.2600.2982_none_deadbeef.manifest
           ;;
        esac
        echo "\"$1\"=\"$mode\"" >> /tmp/override-dll.reg
    shift
    done

    "$WINE" regedit /tmp/override-dll.reg
    rm /tmp/override-dll.reg
}
export -f winebottlerOverrideDlls



##########                     File downloading                       ##########
################################################################################
winebottlerDownload() {
    if [ $# -ne 2 ]; then
        filename=$(basename ${1})
    else
        filename="${2}"
    fi
	
	if [ "$socks5_proxy"  != "" ]; then
		curl --socks5-hostname "$socks5_proxy" -s -L -o "$filename" -C - --header "Accept-Encoding: gzip,deflate" ${1}
	else
		curl -s -L -o "$filename" -C - --header "Accept-Encoding: gzip,deflate" ${1}
	fi
}
export -f winebottlerDownload



##########                Create a new app container                  ##########
################################################################################
winebottlerApp () {
    echo "###BOTTLING### Create .app..."

    #create app layout (copy file by file to not destroy a template
	mkdir -p "$BOTTLE/Contents/Resources/"
    ditto "$BUNDLERESOURCEPATH/WineBottlerStarter.app/Contents/Frameworks" "$BOTTLE/Contents/Frameworks/"
    ditto "$BUNDLERESOURCEPATH/WineBottlerStarter.app/Contents/MacOS" "$BOTTLE/Contents/MacOS"
	ditto "$BUNDLERESOURCEPATH/WineBottlerStarter.app/Contents/PkgInfo" "$BOTTLE/Contents/PkgInfo"
	ditto "$BUNDLERESOURCEPATH/WineBottlerStarter.app/Contents/Resources" "$BOTTLE/Contents/Resources/"

    #Info.plist
    cat > "$BOTTLE/Contents/Info.plist" <<_EOF_
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>WineProgramPath</key>
    <string>$PATH_TO_EXECUTABLE</string>
    <key>WineProgramArguments</key>
    <string>$EXECUTABLE_ARGUMENTS</string>
    <key>CFBundleDevelopmentRegion</key>
    <string>English</string>
    <key>CFBundleExecutable</key>
    <string>WineBottlerStarter</string>
    <key>CFBundleIdentifier</key>
    <string>org.kronenberg.WineBottler_$(basename -s .app "$BOTTLE")</string>
    <key>CFBundleInfoDictionaryVersion</key>
    <string>6.0</string>
    <key>CFBundleName</key>
    <string>$(basename -s .app "$BOTTLE")</string>
    <key>CFBundlePackageType</key>
    <string>APPL</string>
    <key>CFBundleSignature</key>
    <string>????</string>
    <key>CFBundleVersion</key>
    <string>$EXECUTABLE_VERSION</string>
    <key>CFBundleShortVersionString</key>
    <string>$EXECUTABLE_VERSION</string>
    <key>NSMainNibFile</key>
    <string>MainMenu</string>
    <key>NSPrincipalClass</key>
    <string>NSApplication</string>
	<key>CFBundleIconFile</key>
	<string>Icon.icns</string>
    <key>CFBundleDocumentTypes</key>
	<array>
        <dict>
            <key>CFBundleTypeExtensions</key>
            <array>
                <string>*</string>
            </array>
            <key>CFBundleTypeName</key>
            <string>All</string>
            <key>CFBundleTypeRole</key>
            <string>Editor</string>
            <key>LSTypeIsPackage</key>
            <false/>
            <key>NSPersistentStoreTypeKey</key>
            <string>Binary</string>
        </dict>
    </array>
</dict>
</plist>
_EOF_
}
export -f winebottlerApp



##########            Registering OS X corefonts in prefix            ##########
################################################################################
winebottlerRegisterOSXCoreFonts() {
    echo "###BOTTLING### Registering Truetype Fonts..."
    cat > /tmp/register-font.reg <<_EOF_
REGEDIT4

[HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Fonts]
"Arial Black (TrueType)"="Arial Black.ttf"
"Arial Bold Italic (TrueType)"="Arial Bold Italic.ttf"
"Arial Bold (TrueType)"="Arial Bold.ttf"
"Arial Italic (TrueType)"="Arial Italic.ttf"
"Arial Narrow Bold Italic (TrueType)"="Arial Narrow Bold Italic.ttf"
"Arial Narrow Bold (TrueType)"="Arial Narrow Bold.ttf"
"Arial Narrow Italic (TrueType)"="Arial Narrow Italic.ttf"
"Arial Narrow (TrueType)"="Arial Narrow.ttf"
"Arial Rounded Bold (TrueType)"="Arial Rounded Bold.ttf"
"Arial Unicode (TrueType)"="Arial Unicode.ttf"
"Arial (TrueType)"="Arial.ttf"
"Ayuthaya (TrueType)"="Ayuthaya.ttf"
"Baghdad (TrueType)"="Baghdad.ttf"
"Brush Script (TrueType)"="Brush Script.ttf"
"Comic Sans MS Bold (TrueType)"="Comic Sans MS Bold.ttf"
"Comic Sans MS (TrueType)"="Comic Sans MS.ttf"
"Courier New Bold Italic (TrueType)"="Courier New Bold Italic.ttf"
"Courier New Bold (TrueType)"="Courier New Bold.ttf"
"Courier New Italic (TrueType)"="Courier New Italic.ttf"
"Courier New (TrueType)"="Courier New.ttf"
"Georgia Bold Italic (TrueType)"="Georgia Bold Italic.ttf"
"Georgia Bold (TrueType)"="Georgia Bold.ttf"
"Georgia Italic (TrueType)"="Georgia Italic.ttf"
"Georgia (TrueType)"="Georgia.ttf"
"Impact (TrueType)"="Impact.ttf"
"Microsoft Sans Serif (TrueType)"="Microsoft Sans Serif.ttf"
"Tahoma Bold (TrueType)"="Tahoma Bold.ttf"
"Tahoma (TrueType)"="Tahoma.ttf"
"Times New Roman Bold Italic (TrueType)"="Times New Roman Bold Italic.ttf"
"Times New Roman Bold (TrueType)"="Times New Roman Bold.ttf"
"Times New Roman Italic (TrueType)"="Times New Roman Italic.ttf"
"Times New Roman (TrueType)"="Times New Roman.ttf"
"Trebuchet MS Bold Italic (TrueType)"="Trebuchet MS Bold Italic.ttf"
"Trebuchet MS Bold (TrueType)"="Trebuchet MS Bold.ttf"
"Trebuchet MS Italic (TrueType)"="Trebuchet MS Italic.ttf"
"Trebuchet MS (TrueType)"="Trebuchet MS.ttf"
"Verdana Bold Italic (TrueType)"="Verdana Bold Italic.ttf"
"Verdana Bold (TrueType)"="Verdana Bold.ttf"
"Verdana Italic (TrueType)"="Verdana Italic.ttf"
"Verdana (TrueType)"="Verdana.ttf"
"Webdings (TrueType)"="Webdings.ttf"
"Wingdings 2 (TrueType)"="Wingdings 2.ttf"
"Wingdings 3 (TrueType)"="Wingdings 3.ttf"
"Wingdings (TrueType)"="Wingdings.ttf"
_EOF_
	winebottlerTry "$WINE" regedit /tmp/register-font.reg
    winebottlerTry rm /tmp/register-font.reg
}
export -f winebottlerRegisterOSXCoreFonts



##########              Registering OS X fonts in prefix              ##########
################################################################################
winebottlerRegisterFont() {
    file=$1
    shift
    font=$1
    cat > /tmp/register-font.reg <<_EOF_
REGEDIT4

[HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\Fonts]
"$font"="$file"
_EOF_
    winebottlerTry "$WINE" regedit /tmp/register-font.reg
    winebottlerTry rm /tmp/register-font.reg
}
export -f winebottlerRegisterFont



##########                    Antialiasing support                    ##########
################################################################################
winebottlerAntialiasing() {
    echo "###BOTTLING### Enabling Antialiasing..."

    cat > /tmp/antialiasing.reg <<_EOF_
REGEDIT4

[HKEY_CURRENT_USER\Control Panel\Desktop]
"FontSmoothing"="2"
"FontSmoothingType"=dword:00000002
"FontSmoothingGamma"=dword:00000578
"FontSmoothingOrientation"=dword:0000000

_EOF_
    winebottlerTry "$WINE" regedit /tmp/antialiasing.reg
    winebottlerTry rm /tmp/antialiasing.reg
}
export -f winebottlerAntialiasing



##########                     coreaudio support                      ##########
################################################################################
winebottlerCoreaudio() {
    echo "###BOTTLING### Turn on Coreaudio..."
    
    cat > /tmp/coreaudio.reg <<_EOF_
REGEDIT4

[HKEY_CURRENT_USER\Software\Wine\Drivers]
"Audio"="coreaudio"

_EOF_
    winebottlerTry "$WINE" regedit /tmp/coreaudio.reg
    winebottlerTry rm /tmp/coreaudio.reg
}
export -f winebottlerCoreaudio



##########                          sandbox                           ##########
################################################################################
winebottlerSandbox () {
    echo "###BOTTLING### Sandboxing..."
	
    winebottlerTry find "$WINEPREFIX/drive_c/users/$USER" -name '*' -type l -exec sh -c 'rm "{}"; mkdir -p "{}"' \;
}
export -f winebottlerSandbox



##########                       create prefix                        ##########
################################################################################
winebottlerPrefix () {

    winebottlerCoreaudio
	wait
	[ "$WINE_VERSION" != "1.0.1" ] && {
		winebottlerSandbox
		wait
	}
    winebottlerAntialiasing
	wait
	cd "$WINEPREFIX/drive_c/windows"
	winebottlerTry rm -rf "$WINEPREFIX/drive_c/windows/system"
	wait
	winebottlerTry ln -s "system32" "system"
	wait
    echo "###BOTTLING### Installing Truetype Fonts..."
    find /Library/Fonts -name \*.ttf -exec sh -c 'ln -s "{}" "$WINEPREFIX/drive_c/windows/Fonts/`basename "{}"`"' \;
    find ~/Library/Fonts -name \*.ttf -exec sh -c 'ln -s "{}" "$WINEPREFIX/drive_c/windows/Fonts/`basename "{}"`"' \;
	winebottlerRegisterOSXCoreFonts
	wait
    cd -
    winebottlerTry "$WINESERVER" -k
	wait
		
	mv "$BOTTLE/Contents/Info.plist" "$BOTTLE/Contents/Info.plist2"
	sed "s/%ProgramFiles%/$( sed 's/\\/\\\\/g' <<< $("$WINE" cmd.exe /c echo %ProgramFiles% | tr -d "\015"))/" "$BOTTLE/Contents/Info.plist2" > "$BOTTLE/Contents/Info.plist"
	rm "$BOTTLE/Contents/Info.plist2"
}
export -f winebottlerPrefix



##########                  Add items from winetricks                  #########
################################################################################
function winebottlerWinetricks() {
	[ "$WINETRICKS_ITEMS" != "" ] && {
	
        # prepare winetricks
        #head -$(($(cat "$HOME/Library/Application Support/Wine/winetricks" | grep -n "execute_command()" | sed 's/[^0-9]//g') - 2)) "$HOME/Library/Application Support/Wine/winetricks" > "$NOSPACE_PATH/winetricks.sh"
        #cat "$HOME/Library/Application Support/Wine/customverbs" >> "$NOSPACE_PATH/winetricks.sh"
        #tail -$(($(wc -l "$HOME/Library/Application Support/Wine/winetricks" | sed 's/[^0-9]//g') - $(cat "$HOME/Library/Application Support/Wine/winetricks" | grep -n "execute_command()" | sed 's/[^0-9]//g') + 2)) "$HOME/Library/Application Support/Wine/winetricks" >> "$NOSPACE_PATH/winetricks.sh"
        cp "$HOME/Library/Application Support/Wine/winetricks" "$NOSPACE_PATH/winetricks.sh"

		# PROXY support
		if [ "$socks5_proxy"  != "" ]; then
			SaveSocks5_proxy=`echo "$socks5_proxy" | sed 's:[]\[\^\$\.\*\/]:\\\\&:g'`
			mv "$NOSPACE_PATH/winetricks.sh" "$NOSPACE_PATH/winetricks.sh2"
			sed 's/try curl /try curl --socks5-hostname $SaveSocks5_proxy /g' "$NOSPACE_PATH/winetricks.sh2" > "$NOSPACE_PATH/winetricks.sh"
			rm "$NOSPACE_PATH/winetricks.sh2"
		fi
		
		# WORKAROUND create a "no-spaces environment"
		WINESAVE=$WINE
		PATHSAVE=$PATH
		PREFSAVE=$WINEPREFIX
		ln -s "$WINEPATH/wine" "$NOSPACE_PATH/wine"
		ln -s "$(which cabextract)" "/$NOSPACE_PATH/cabextract"
		ln -s "$WINEPREFIX" "$NOSPACE_PATH/wineprefix"
		export PATH="$NOSPACE_PATH":$PATH
		export WINE="$NOSPACE_PATH/wine"
		export WINEPREFIX="$NOSPACE_PATH/wineprefix"

		# APPLY winetricks
		for W in $WINETRICKS_ITEMS; do
			echo "###BOTTLING### installing $W"
			winebottlerTry sh "$NOSPACE_PATH/winetricks.sh" --no-isolate $SILENT $W
		done
		winebottlerTry rm "$NOSPACE_PATH/winetricks.sh"
		
		# /WORKAROUND create "no-spaces environment"
		export WINE="$WINESAVE"
		export PATH=$PATHSAVE
		export WINEPREFIX="$PREFSAVE"

		# CLEANUP
		rm -rf "$NOSPACE_PATH" &> /dev/null
	}
}
export -f winebottlerWinetricks



##########                         Proxy                               #########
################################################################################
function winebottlerProxy () {
    [ "$http_proxy" != "" ] && {
		echo "###BOTTLING### Enabling HTTP Proxy..."
    
		cat > /tmp/proxy.reg <<_EOF_
REGEDIT4

[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings]
"MigrateProxy"=dword:00000001
"ProxyEnable"=dword:00000001
"ProxyHttp1.1"=dword:00000000
"ProxyServer"="http://$http_proxy"
"ProxyOverride"="<local>"

_EOF_
		winebottlerTry "$WINE" regedit /tmp/proxy.reg
		winebottlerTry rm /tmp/proxy.reg
    }
	
	[ "$socks5_proxy" != "" ] && {
		echo "###BOTTLING### Enabling Socks5 Proxy..."
    
		cat > /tmp/proxy.reg <<_EOF_
REGEDIT4

[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Internet Settings]
"MigrateProxy"=dword:00000001
"ProxyEnable"=dword:00000001
"ProxyHttp1.1"=dword:00000000
"ProxyServer"="http://$socks5_proxy"
"ProxyOverride"="<local>"

_EOF_
		winebottlerTry "$WINE" regedit /tmp/proxy.reg
		winebottlerTry rm /tmp/proxy.reg
    }
}
export -f winebottlerProxy



##########                       Overrides                             #########
################################################################################
function winebottlerOverride () {
    echo "###BOTTLING### Registering native dlls..."
    [ "$DLL_OVERRIDES"  != "" ] && {
        winebottlerOverrideDlls native,builtin $DLL_OVERRIDES
    }
}
export -f winebottlerOverride



##########                         Builtin                             #########
################################################################################
function winebottlerBuiltin () {
    echo "###BOTTLING### Registering builtin dlls..."
    [ "$DLL_BUILTINS"  != "" ] && {
        winebottlerOverrideDlls builtin $DLL_BUILTINS
    }
}
export -f winebottlerBuiltin



##########                      Installation                           #########
################################################################################
function winebottlerInstall () {

	#no .desktop links
	export WINEDLLOVERRIDES=winemenubuilder.exe=d
	
    #do we have to download it first?
    if test $(echo $INSTALLER_FILENAME | grep http://); then
        echo "###BOTTLING### Downloading $(basename $INSTALLER_FILENAME)..."
		winebottlerTry rm "$WINEPREFIX/dosdevices/z:"
        winebottlerDownload "$INSTALLER_FILENAME" "$WINEPREFIX/drive_c/windows/temp/$(basename "$INSTALLER_FILENAME")"
		
		echo "###BOTTLING### Installing $(basename $INSTALLER_FILENAME)..."
		if test $(echo $INSTALLER_FILENAME | grep .msi); then
			winebottlerTryMsi "$WINE" msiexec /i "C:\\windows\\temp\\$(basename $INSTALLER_FILENAME)" $INSTALLER_SWITCHES
		else
			winebottlerTry "$WINE" "C:\\windows\\temp\\$(basename "$INSTALLER_FILENAME")" $INSTALLER_SWITCHES
		fi
		winebottlerTry ln -s "/" "$WINEPREFIX/dosdevices/z:"
		winebottlerTry rm "$WINEPREFIX/drive_c/windows/temp/$(basename "$INSTALLER_FILENAME")"
	
    else
		echo "###BOTTLING### Installing $(basename $INSTALLER_FILENAME)..."
	
		# only copy
		if test $(echo $INSTALLER_SWITCHES | grep WINEBOTTLERCOPYONLY); then
			mkdir "$WINEPREFIX/drive_c/winebottler"
			cp "$INSTALLER_FILENAME" "$WINEPREFIX/drive_c/winebottler/"
		else
			cd "$(dirname "$INSTALLER_FILENAME")"
			if test $(echo $INSTALLER_FILENAME | grep .msi); then
				winebottlerTryMsi "$WINE" msiexec /i "$INSTALLER_FILENAME" $INSTALLER_SWITCHES
            elif test $(echo $INSTALLER_FILENAME | grep .bat); then
                winebottlerTry "$WINE" cmd.exe /c start /Unix "$INSTALLER_FILENAME" $INSTALLER_SWITCHES
            else
				winebottlerTry "$WINE" "$INSTALLER_FILENAME" $INSTALLER_SWITCHES
			fi
			cd -
		fi
		
    fi
	
	#fix permissions
	chmod -R a+rw "$WINEPREFIX"
}
export -f winebottlerInstall