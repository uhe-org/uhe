[Rainmeter]
@Include=#@#Variables/mainvariables.inc
Group=RelativeToScreenWidth | AllSkins

[Variables]
Win10TaskbarHeight=40
Win11TaskbarHeight=48

[measureWinVer]
Measure=Registry
RegHKey=HKEY_LOCAL_MACHINE
RegKey=SOFTWARE\Microsoft\Windows NT\CurrentVersion
RegValue=CurrentBuild
UpdateDivider=-1
IfCondition=measureWinVer < 22000
IfTrueAction=[!SetOption meterMiddle H #Win10TaskbarHeight#]
IfFalseAction=[!SetOption meterMiddle H #Win11TaskbarHeight#]

[meterMiddle]
Meter=Shape
Shape=Rectangle 0,0,#SCREENAREAWIDTH#,#Win11TaskbarHeight#,#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup
