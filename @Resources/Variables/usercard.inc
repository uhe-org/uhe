[Rainmeter]
@Include=mainvariables.inc
ContextTitle2="Edit base usercard"
ContextAction2=["#@#Variables/usercard.inc"]

[Variables]
Width=400
InfoWidth=300
BaseFinishAction=[!ShowMeter meterCard][!UpdateMeter meterCardBackground][!Redraw]
BaseOnRegExpErrorAction=[!Redraw]
Minimal=1

[measureMinimal]
Measure=Calc
IfCondition=(#Minimal# = 1)
IfTrueAction=[!HideMeterGroup ImageGroup][!DisableMeasure measureMinimal]
IfFalseAction=[!ShowMeterGroup ImageGroup][!DisableMeasure measureMinimal]
Disabled=1

[measureData]
Measure=WebParser
FinishAction=#BaseFinishAction#
OnRegExpErrorAction=#BaseOnRegExpErrorAction#

[meterAvatarBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterCard:H],[meterCard:H],#CornerRadius# | StrokeWidth 0
DynamicVariables=1
Group=ImageGroup
Hidden=1

[meterCardContainer]
Meter=Shape
Shape=Rectangle 0,0,[meterCard:W],[meterCard:H],#CornerRadius# | StrokeWidth 0
DynamicVariables=1
X=R

[meterCardBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterCard:W],[meterCard:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup
X=r

[meterAvatar]
Meter=Image
DynamicVariables=1
W=[meterCard:H]
Group=ImageGroup
Container=meterAvatarBackground
Hidden=1

[meterCover]
Meter=Image
DynamicVariables=1
H=[meterCard:H]
W=#InfoWidth#
PreserveAspectRatio=2
Group=ImageGroup
Container=meterCardContainer

[meterCard]
Meter=String
FontFace=#FontFace#
FontSize=12
Padding=#PaddingSize#
AntiAlias=1
X=r
W=(#InfoWidth# - (#SidePadding# * 2))
Group=TextGroup
