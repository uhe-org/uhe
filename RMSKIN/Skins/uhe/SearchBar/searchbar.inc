[Rainmeter]
@Include=#@#Variables/mainvariables.inc
ContextTitle2="Edit base search bar"
ContextAction2=["#CURRENTPATH#searchbar.inc"]

[Variables]
icon=[\xf002]

[measureInput]
Measure=Plugin
Plugin=InputText
X=(20 + (#SidePadding# * 2))
W=(190 + (#SidePadding# * 2))
H=(16 + (#SidePadding# * 2))
FontSize=14
FontFace=#FontFace#
AntiAlias=1
DefaultValue=type to search
Command1=["#URL#"]
Group=TextGroup | TextBoxGroup

[meterMiddleBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterMiddle:W],[meterMiddle:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
Shape2=Rectangle (20 + (#SidePadding# * 2)),0,([meterMiddle:W] - (20 + (#SidePadding# * 2))),[meterMiddle:H],#CornerRadius# | StrokeWidth 0
;add placeholder option to hide errors
Shape3=Combine Shape | Exclude Shape2
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup

[meterMiddleBackground2]
Meter=Shape
Shape=Rectangle (20 + (#SidePadding# * 2)),0,([meterMiddle:W] - (20 + (#SidePadding# * 2))),[meterMiddle:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup

[meterMiddleHover]
Meter=Shape
Shape=Rectangle (20 + (#SidePadding# * 2)),0,([meterMiddle:W] - (20 + (#SidePadding# * 2))),[meterMiddle:H],#CornerRadius# | Extend Highlight | StrokeWidth 0
;add placeholder option to hide errors
Highlight=Fill Color 0,0,0,0
DynamicVariables=1

[meterMiddle]
Meter=String
W=230
FontFace=#IconFace#
AntiAlias=1
FontSize=12
FontFace=#FontFace#
Text=#icon#
Padding=#PaddingSize#
LeftMouseUpAction=#PlayButtonClick#[!CommandMeasure measureInput "ExecuteBatch 1"]
Group=TextGroup
MouseOverAction=[!SetOption meterMiddleHover Highlight "Fill Color #LightHighlight#,#NoGradientTransparency#"][!UpdateMeter meterMiddleHover][!Redraw]
MouseLeaveAction=[!SetOption meterMiddleHover Highlight "Fill Color 0,0,0,0"][!UpdateMeter meterMiddleHover][!Redraw]
