[Rainmeter]
@Include=#@#Variables/mainvariables.inc

[Variables]
ButtonWidth=100
ButtonHeight=50

[measureUpKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Up#
KeyDownAction=[!SetOption meterUpKeyHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterUpKeyHover][!Redraw]
KeyUpAction=[!SetOption meterUpKeyHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterUpKeyHover][!Redraw]

[measureLeftKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Left#
KeyDownAction=[!SetOption meterLeftKeyHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterLeftKeyHover][!Redraw]
KeyUpAction=[!SetOption meterLeftKeyHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterLeftKeyHover][!Redraw]

[measureDownKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Down#
KeyDownAction=[!SetOption meterDownKeyHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterDownKeyHover][!Redraw]
KeyUpAction=[!SetOption meterDownKeyHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterDownKeyHover][!Redraw]

[measureRightKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Right#
KeyDownAction=[!SetOption meterRightKeyHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterRightKeyHover][!Redraw]
KeyUpAction=[!SetOption meterRightKeyHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterRightKeyHover][!Redraw]

[meterUpKeyBackground]
Meter=Shape
X=#ButtonWidth#
Shape=Rectangle 0,0,#ButtonWidth#,#ButtonHeight#,#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup

[meterUpKeyHover]
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

[meterLeftKeyHover]
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

[meterDownKeyHover]
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

[meterRightKeyHover]
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
