[Rainmeter]
@Include=#@#Variables/mainvariables.inc
ContextTitle3="Edit base custom taskbar"
ContextAction3=["#CURRENTPATH#../custom-taskbar.inc"]

[measureWinVer]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=CurrentBuild
UpdateDivider=-1
; Windows 10+
IfCondition=(measureWinVer >= 10240)

[meterMiddle]
Meter=Shape
Shape=Rectangle 0,0,#SCREENAREAWIDTH#,(#SCREENAREAHEIGHT# - #WORKAREAHEIGHT#),#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=TaskbarGroup
