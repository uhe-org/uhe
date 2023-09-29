[Rainmeter]
@Include=mainvariables.inc
ContextTitle2="Edit side icon variables"
ContextAction2=["#@#Variables/sideiconvariables.inc"]
Group=IconSkins | AllSkins

[measureIconSetting]
Measure=Calc
DynamicVariables=1
Formula=#Icons#
IfCondition=measureIconSetting = 1
IfTrueAction=[!SetVariable Label "#icon# "][!SetOption meterTooltip Text #text#][!UpdateMeter meterSide][!Redraw]
IfFalseAction=[!SetVariable Label "#text#:"][!SetOption meterTooltip Text ""][!UpdateMeter meterSide][!Redraw]

[meterBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterSide:W],[meterSide:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup

[meterSide]
Meter=String
W=(160 - (#SidePadding# * 2))
FontFace=#FontFace#
FontSize=15
Padding=#PaddingSize#
AntiAlias=1
InlineSetting=Face | #IconFace#
InlinePattern=#icon#
DynamicVariables=1
Text=#Label# %1
Group=TextGroup
MouseOverAction=[!ShowMeter meterTooltip][!Redraw]
MouseLeaveAction=[!HideMeter meterTooltip][!Redraw]

[meterBar]
Meter=Bar
Y=R
W=(160-#CornerRadius# * 2)
H=5
X=#CornerRadius#
BarOrientation=Horizontal
BarColor=#LightHighlight#
SolidColor=#BarBackgroundColor#

[meterTooltip]
Meter=String
FontFace=#FontFace#
FontSize=10
AntiAlias=1
X=160
StringAlign=Right
Group=TextGroup
Hidden=1
Padding=5,5,5,5
