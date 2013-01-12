#!/bin/sh



##########               Import wineBottlerFunctions                   #########
################################################################################
echo "###BOTTLING### default.sh"
source "$BUNDLERESOURCEPATH/bottler.sh"



##########               Default Installation Script                   #########
################################################################################
winebottlerApp
[ "$TEMPLATE" == "" ] && {
	winebottlerPrefix
}
winebottlerWinetricks
winebottlerOverride
winebottlerInstall
winebottlerProxy

echo "###FINISHED###"
echo "###MAKESUREFINISHDISGETTINGTHRU###"
sleep 1
wait
echo "###MAKESUREFINISHDISGETTINGTHRU###"
exit 0