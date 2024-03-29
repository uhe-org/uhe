[Rainmeter]
@Include=#@#Variables/mainvariables.inc
OnRefreshAction=[!ActivateConfig "uhe\Dialogs\Dim"][!SetWindowPosition 50% 50% 50% 50%][!ZPos 2]
OnCloseAction=[!DeactivateConfig "uhe\Dialogs\Dim"]

[Variables]
Width=200

[meterLabelBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterLabel:W],[meterLabel:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup

[meterLabel]
Meter=String
FontSize=22
FontFace=#DisplayFont#
AntiAlias=1
W=(#Width# - (#SidePadding# * 2))
Padding=#PaddingSize#
Group=TextGroup
Text=#Label#

[meterDescriptionBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterLabel:W],[meterDescription:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup
Y=R

[meterDescription]
Meter=String
Group=TextGroup
Text="#RequestedItem#" #Description#
ClipString=2
AntiAlias=1
Padding=#PaddingSize#
Y=r
FontFace=#FontFace#
W=(#Width# - (#SidePadding# * 2))
DynamicVariables=1
OnUpdateAction=[!UpdateMeter meterDescriptionBackground]

[meterYesButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterYesButton:W],[meterYesButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup
Y=R

[meterYesButton]
Meter=String
Group=TextGroup
Text=Yes
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 4)
W=(#Width# / 2)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!DeactivateConfig]#YesAction#[!Redraw]
FontFace=#FontFace#

[measureNoButtonBackground]
Meter=Shape
Shape=Rectangle 0,0,[measureNoButton:W],[measureNoButton:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup
Y=r
X=(#Width# / 2)

[measureNoButton]
Meter=String
Group=TextGroup
Text=No
AntiAlias=1
Padding=0,#SidePadding#,0,#SidePadding#
Y=r
X=(#Width# / 4)r
W=(#Width# / 2)
StringAlign=Center
LeftMouseUpAction=#PlayButtonClick#[!DeactivateConfig][!Redraw]
FontFace=#FontFace#
