[Rainmeter]
@Include=#@#Variables/mainvariables.inc
ContextTitle2="Edit base controls"
ContextAction2=["#CURRENTPATH#controls.inc"]

[Variables]
backwardButton=[\xf048]
playIcon=[\xf144]
pauseIcon=[\xf28b]
forwardButton=[\xf051]
buttonSize=(30 + (#SidePadding# * 2))

[measurePlayer]
Measure=NowPlaying
PlayerType=State
IfCondition=measurePlayer = 1
IfTrueAction=[!SetOption meterPlayPause Text #pauseIcon#][!UpdateMeter meterPlayPause][!Redraw]
IfFalseAction=[!SetOption meterPlayPause Text #playIcon#][!UpdateMeter meterPlayPause][!Redraw]

[styleButtonBackground]
Group=BackgroundGroup
X=(#buttonSize# / 2)r
W=#buttonSize#
H=#buttonSize#
DynamicVariables=1

[styleButton]
Group=TextGroup
MeasureName=measurePlayer
FontFace=#IconFace#
DynamicVariables=1
AntiAlias=1
FontSize=20
X=(-#buttonSize# / 2)R
Y=(#buttonSize# / 2)
W=#buttonSize#
H=#buttonSize#
StringAlign=CenterCenter

[meterBackwardBackground]
Meter=Shape
MeterStyle=styleButtonBackground
Shape=Rectangle 0,0,[meterBackward:W],[meterBackward:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
X=0
LeftMouseUpAction=#PlayButtonClick#[!CommandMeasure measurePlayer Previous][!UpdateMeasure measurePlayer][!UpdateMeter meterBackwardBackground][!Redraw]

[meterBackwardHover]
Meter=Shape
MeterStyle=styleButtonBackground
X=r
Shape=Rectangle 0,0,[meterBackward:W],[meterBackward:H],#CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0

[meterBackward]
Meter=String
MeterStyle=styleButton
Text=#backwardButton#
MouseOverAction=[!SetOption meterBackwardHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterBackwardHover][!Redraw]
MouseLeaveAction=[!SetOption meterBackwardHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterBackwardHover][!Redraw]

[meterPlayPauseBackground]
Meter=Shape
MeterStyle=styleButtonBackground
Shape=Rectangle 0,0,[meterPlayPause:W],[meterPlayPause:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
LeftMouseUpAction=#PlayButtonClick#[!CommandMeasure measurePlayer PlayPause][!UpdateMeasure measurePlayer][!UpdateMeter meterPlayPauseBackground][!Redraw]
Group=OpaqueBackgroundGroup

[meterPlayPauseHover]
Meter=Shape
MeterStyle=styleButtonBackground
X=r
Shape=Rectangle 0,0,[meterPlayPause:W],[meterPlayPause:H],#CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0

[meterPlayPause]
Meter=String
MeterStyle=styleButton
Text=#playIcon#
MouseOverAction=[!SetOption meterPlayPauseHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterPlayPauseHover][!Redraw]
MouseLeaveAction=[!SetOption meterPlayPauseHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterPlayPauseHover][!Redraw]

[meterForwardBackground]
Meter=Shape
MeterStyle=styleButtonBackground
Shape=Rectangle 0,0,[meterForward:W],[meterForward:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
LeftMouseUpAction=#PlayButtonClick#[!CommandMeasure measurePlayer Next][!UpdateMeasure measurePlayer][!UpdateMeter meterForwardBackground][!Redraw]

[meterForwardHover]
Meter=Shape
MeterStyle=styleButtonBackground
X=r
Shape=Rectangle 0,0,[meterForward:W],[meterForward:H],#CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0

[meterForward]
Meter=String
MeterStyle=styleButton
Text=#forwardButton#
MouseOverAction=[!SetOption meterForwardHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterForwardHover][!Redraw]
MouseLeaveAction=[!SetOption meterForwardHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterForwardHover][!Redraw]
