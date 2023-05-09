[Rainmeter]
ContextTitle3="Edit osu! variables"
ContextAction3=["#@#Variables/osuvariables.inc"]

[Variables]
Username=Joehu
UserID=8549835
HostName=https://osu.ppy.sh/api/v2
Mode=osu

[measureToken]
Measure=Plugin
Plugin=RunCommand
Parameter=curl -s -d "client_id=%UheOsuClientID%&client_secret=%UheOsuClientSecret%&grant_type=client_credentials&scope=public" -X POST "https://osu.ppy.sh/oauth/token"
UpdateDivider=-1
OutputType=ANSI
RegExpSubstitute=1
Substitute='.*"access_token":"(.+)"}':"\1"
FinishAction=[!SetVariable generatedToken [measureToken]][!UpdateMeasure measureSetToken][!CommandMeasure measureSetToken Run]

[measureSetToken]
Measure=Plugin
Plugin=RunCommand
DynamicVariables=1
Parameter=setx UheOsuToken #generatedToken#
FinishAction=[!ActivateConfig "uhe\Dialogs\Quit"][!SetVariable RequestedSkin "osu! usercard" "uhe\Dialogs\Quit"][!Update "uhe\Dialogs\Quit"]
OutputType=UTF8
