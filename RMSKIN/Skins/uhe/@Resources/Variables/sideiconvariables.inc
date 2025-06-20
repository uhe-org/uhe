[Rainmeter]
@Include=mainvariables.inc
ContextTitle3="Edit side icon variables"
ContextAction3=["#@#Variables/sideiconvariables.inc"]
Group=IconSkins | AllSkins

[Variables]
BackgroundGroup=BackgroundGroup
BarBackground=#BarBackgroundColor#
BarHeight=5
Width=130

[measureIconSetting]
Measure=Calc
DynamicVariables=1
Formula=#Icons#
IfCondition=measureIconSetting = 1
IfTrueAction=[!SetVariable Label "#icon# "][!SetOption meterTooltip Text #text#][!UpdateMeter meterSide][!Redraw]
IfFalseAction=[!SetVariable Label "#text#:"][!SetOption meterTooltip Text ""][!UpdateMeter meterSide][!Redraw]

[meterBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterSide:W],([meterSide:H] + #BarHeight#),#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=#BackgroundGroup#

[meterSide]
Meter=String
W=(#Width# - (#SidePadding# * 2))
FontFace=#FontFace#
FontSize=12
Padding=#PaddingSize#
AntiAlias=1
InlineSetting=Face | #IconFace#
InlinePattern=#icon#
DynamicVariables=1
Text=#Label# %1
Group=TextGroup
MouseOverAction=[!ShowMeter meterTooltip][!Redraw]
MouseLeaveAction=[!HideMeter meterTooltip][!Redraw]

[meterBarContainer]
Meter=Shape
Shape=Rectangle 0,0,(#Width# - #CornerRadius# * 2),#BarHeight#,(#CornerRadius# / 2) | StrokeWidth 0
;add placeholder option to hide errors
DynamicVariables=1
X=#CornerRadius#
Y=([meterBackground:H] - #BarHeight# - #CornerRadius# / 2)

[meterBar]
Meter=Bar
W=(#Width# - #CornerRadius# * 2)
H=#BarHeight#
BarOrientation=Horizontal
BarColor=#LightHighlight#
Container=meterBarContainer
SolidColor=#BarBackground#

[meterTooltip]
Meter=String
FontFace=#FontFace#
FontSize=10
AntiAlias=1
X=#Width#
StringAlign=Right
Group=TextGroup
Hidden=1
Padding=5,5,5,5
