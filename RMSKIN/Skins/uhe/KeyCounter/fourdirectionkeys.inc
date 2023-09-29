[Rainmeter]
@Include=#@#Variables/mainvariables.inc

[Variables]
ButtonWidth=100
ButtonHeight=50

[measureUpKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Up#
KeyDownAction=[!SetOption meterUpKeyHighlight Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterUpKeyHighlight][!Redraw]
KeyUpAction=[!SetOption meterUpKeyHighlight Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterUpKeyHighlight][!Redraw]

[measureLeftKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Left#
KeyDownAction=[!SetOption meterLeftKeyHighlight Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterLeftKeyHighlight][!Redraw]
KeyUpAction=[!SetOption meterLeftKeyHighlight Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterLeftKeyHighlight][!Redraw]

[measureDownKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Down#
KeyDownAction=[!SetOption meterDownKeyHighlight Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterDownKeyHighlight][!Redraw]
KeyUpAction=[!SetOption meterDownKeyHighlight Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterDownKeyHighlight][!Redraw]

[measureRightKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Right#
KeyDownAction=[!SetOption meterRightKeyHighlight Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterRightKeyHighlight][!Redraw]
KeyUpAction=[!SetOption meterRightKeyHighlight Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterRightKeyHighlight][!Redraw]

[meterUpKeyBackground]
Meter=Shape
X=#ButtonWidth#
Shape=Rectangle 0,0,#ButtonWidth#,#ButtonHeight#,#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup

[meterUpKeyHighlight]
Meter=Shape
Shape=Rectangle 0,0,#ButtonWidth#,#ButtonHeight#,#CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0
DynamicVariables=1
X=r

[meterUpKey]
Meter=String
Text=#Up#
StringAlign=CenterCenter
X=(-#ButtonWidth# / 2)R
Y=(#ButtonHeight# / 2)
W=#ButtonWidth#
H=#ButtonHeight#
FontFace=#FontFace#
FontSize=20
AntiAlias=1
Group=TextGroup

[meterLeftKeyBackground]
Meter=Shape
Y=(#ButtonHeight# / 2)r
Shape=Rectangle 0,0,#ButtonWidth#,#ButtonHeight#,#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup

[meterLeftKeyHighlight]
Meter=Shape
Shape=Rectangle 0,0,#ButtonWidth#,#ButtonHeight#,#CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0
DynamicVariables=1
X=r
Y=r

[meterLeftKey]
Meter=String
Text=#Left#
StringAlign=CenterCenter
X=(-#ButtonWidth# / 2)R
Y=(#ButtonHeight# / 2)r
W=#ButtonWidth#
H=#ButtonHeight#
FontFace=#FontFace#
FontSize=20
AntiAlias=1
Group=TextGroup

[meterDownKeyBackground]
Meter=Shape
X=(#ButtonWidth# / 2)r
Y=(-#ButtonHeight# / 2)r
Shape=Rectangle 0,0,#ButtonWidth#,#ButtonHeight#,#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup

[meterDownKeyHighlight]
Meter=Shape
Shape=Rectangle 0,0,#ButtonWidth#,#ButtonHeight#,#CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0
DynamicVariables=1
X=r
Y=r

[meterDownKey]
Meter=String
Text=#Down#
StringAlign=CenterCenter
X=(-#ButtonWidth# / 2)R
Y=(#ButtonHeight# / 2)r
W=#ButtonWidth#
H=#ButtonHeight#
FontFace=#FontFace#
FontSize=20
AntiAlias=1
Group=TextGroup

[meterRightKeyBackground]
Meter=Shape
X=(#ButtonWidth# / 2)r
Y=(-#ButtonHeight# / 2)r
Shape=Rectangle 0,0,#ButtonWidth#,#ButtonHeight#,#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup

[meterRightKeyHighlight]
Meter=Shape
Shape=Rectangle 0,0,#ButtonWidth#,#ButtonHeight#,#CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0
DynamicVariables=1
X=r
Y=r

[meterRightKey]
Meter=String
Text=#Right#
StringAlign=CenterCenter
X=(-#ButtonWidth# / 2)R
Y=(#ButtonHeight# / 2)r
W=#ButtonWidth#
H=#ButtonHeight#
FontFace=#FontFace#
FontSize=20
AntiAlias=1
Group=TextGroup
