[Rainmeter]
@Include=mainvariables.inc
ContextTitle3="Edit launcher variables"
ContextAction3=["#@#Variables/launchervariables.inc"]

[Variables]
FontSize=25

[meterIconBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterIcon:W],[meterIcon:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup

[meterIconHover]
Meter=Shape
Shape=Rectangle 0,0,[meterIcon:W],[meterIcon:H],#CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0
DynamicVariables=1

[meterIcon]
Meter=String
AntiAlias=1
FontFace=#IconFace#
FontSize=#FontSize#
Padding=#PaddingSize#
Text=#icon#
Group=TextGroup
MouseOverAction=[!SetOption meterIconHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterIconHover][!Redraw]
MouseLeaveAction=[!SetOption meterIconHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterIconHover][!Redraw]
