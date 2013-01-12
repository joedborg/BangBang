#!/bin/bash

#  winetricksextract.sh
#  WineBottler
#
#  Created by Mike Kronenberg on 04.07.12.
#  Copyright (c) 2012 Tapenta GmbH. All rights reserved.



w_metadata() {
    echo "\t<dict>\n\t\t<key>verb</key>\n\t\t<string>$1</string>\n\t\t<key>category</key>\n\t\t<string>$2</string>\n\t\t<key>status</key>\n\t\t<string>0</string>" >>"$WINETRICKS_TMP"
    shift
    shift
    for arg
    do
        echo "\t\t<key>${arg%%=*}</key>\n\t\t<string>${arg#*=}</string>" >>"$WINETRICKS_TMP"
    done
    echo "\t</dict>" >>"$WINETRICKS_TMP"
}
export -f w_metadata

export WINETRICKS_PLIST="$HOME/Library/Application Support/Wine/winetricks.plist"
export WINETRICKS_TMP="/tmp/winetricks.plist"

# add our custom verbs or just copy it in 1.1.44
#cat "$HOME/Library/Application Support/Wine/winetricks" "$HOME/Library/Application Support/Wine/customverbs" > /tmp/winetricks_custom
cp "$HOME/Library/Application Support/Wine/winetricks" /tmp/winetricks_custom

# remove everything so that we can get the verbs
tr '\n' '^' < /tmp/winetricks_custom | sed -e "s/\$USERNAME/$USER/g" -e 's/\$W_PROGRAMS_X86_WIN/\%ProgramFiles\%/g' -e 's/\$W_SYSTEM32_DLLS_WIN/C:\/windows\/system32/g' -e 's/^.*# Runtimes//' -e 's/#---- Derived Metadata ----.*//' | tr '^' '\n' > "/tmp/winetricks_verbs.sh"

#start plist
echo '<?xml version="1.0" encoding="UTF-8"?>\n<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">\n<plist version="1.0">\n<array>' >"$WINETRICKS_TMP"

# add verbs
source "/tmp/winetricks_verbs.sh"

#end plist
echo "</array>\n</plist>" >>"$WINETRICKS_TMP"

#fix special chars in plist
sed -e 's/\&/\&amp;/g' "$WINETRICKS_TMP" >"$WINETRICKS_TMP"2

#check if the plist validates
xmllint --noout "$WINETRICKS_TMP"2
if [ "$?" -ne "0" ]; then
    echo "\n***** Error:"
    exit
fi

#move the plist in the library
mv "$WINETRICKS_TMP"2 "$WINETRICKS_PLIST"

#cleanup
rm "$WINETRICKS_TMP"
rm /tmp/winetricks_custom


exit 0