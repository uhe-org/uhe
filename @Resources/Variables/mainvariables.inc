;these variables are the design building blocks of skins (i.e. these shouldn't be changed unless there's a significant design change)
;also contains measures that uses these values
[Rainmeter]
AccurateText=1
DynamicWindowSize=1
ContextTitle="Edit main variables"
ContextAction=["#@#Variables/mainvariables.inc"]
@Include=uservariables.inc
@Include3=formattingvariables.inc
@Include4=easingvariables.inc
Group=AllSkins

[Variables]
FontFace=Roboto Condensed
DisplayFont=Bebas Neue
MonospacedFontFace=Ubuntu Mono
HandwritingFont=Dancing Script
IconFace=Font Awesome 6 Free Solid
RegularIconFace=Font Awesome 6 Free
BrandFace=Font Awesome 6 Brands

GradientHigh=200
GradientLow=1
NoGradientTransparency=150

DarkBackgroundColor=50,50,50
DarkerBackgroundColor=0,0,0

LightBackgroundColor=205,205,205
LighterBackgroundColor=255,255,255

ClickableTransparentColor=0,0,0,1

BarBackgroundTransparency=0
BarBackgroundColor=0,0,0,#BarBackgroundTransparency#
LightBarBackgroundColor=0,0,0,#BarBackgroundTransparency#

DarkFontColor=255,255,255
LightFontColor=0,0,0

PoorFontSize=10

SidePadding=10

CornerRadius=10

PaddingSize=#SidePadding#,#SidePadding#,#SidePadding#,#SidePadding#

; samples taken from https://mixkit.co/free-sound-effects/interface/
PlayButtonClick=[Play "#SKINSPATH#/uhe/@Resources/Samples/button-click.wav"]

TextTrueAction=[!SetOptionGroup TextGroup FontColor #DarkFontColor#]
TextTrueAction2=[!SetOptionGroup TextGroup FontColor #LightFontColor#]
TextTrueAction3=[!SetOptionGroup TextGroup FontColor #LightFontColor#]
TextTrueAction4=[!SetOptionGroup TextGroup FontColor #DarkFontColor#]

ImageTrueAction=[!SetOptionGroup SpriteGroup ImageTint #DarkFontColor#]
ImageTrueAction2=[!SetOptionGroup SpriteGroup ImageTint #LightFontColor#]
ImageTrueAction3=[!SetOptionGroup SpriteGroup ImageTint #LightFontColor#]
ImageTrueAction4=[!SetOptionGroup SpriteGroup ImageTint #DarkFontColor#]

BackgroundTrueAction=[!SetOptionGroup BackgroundGroup Gradient "180 | #DarkBackgroundColor#,#GradientHigh# ; 0.0 | #DarkBackgroundColor#,#GradientLow# ; 1.0"]
BackgroundTrueAction2=[!SetOptionGroup BackgroundGroup Gradient "180 | #LightBackgroundColor#,#NoGradientTransparency# ; 0.0 | #LightBackgroundColor#,#NoGradientTransparency# ; 1.0"]
BackgroundTrueAction3=[!SetOptionGroup BackgroundGroup Gradient "180 | #LightBackgroundColor#,#GradientHigh# ; 0.0 | #LightBackgroundColor#,#GradientLow# ; 1.0"]
BackgroundTrueAction4=[!SetOptionGroup BackgroundGroup Gradient "180 | #DarkBackgroundColor#,#NoGradientTransparency# ; 0.0 | #DarkBackgroundColor#,#NoGradientTransparency# ; 1.0"]

OpaqueBackgroundTrueAction=[!SetOptionGroup OpaqueBackgroundGroup Gradient "180 | #DarkerBackgroundColor#,#GradientHigh# ; 0.0 | #DarkerBackgroundColor#,#GradientLow# ; 1.0"]
OpaqueBackgroundTrueAction2=[!SetOptionGroup OpaqueBackgroundGroup Gradient "180 | #LighterBackgroundColor#,#NoGradientTransparency# ; 0.0 | #LighterBackgroundColor#,#NoGradientTransparency# ; 1.0"]
OpaqueBackgroundTrueAction3=[!SetOptionGroup OpaqueBackgroundGroup Gradient "180 | #LighterBackgroundColor#,#GradientHigh# ; 0.0 | #LighterBackgroundColor#,#GradientLow# ; 1.0"]
OpaqueBackgroundTrueAction4=[!SetOptionGroup OpaqueBackgroundGroup Gradient "180 | #DarkerBackgroundColor#,#NoGradientTransparency# ; 0.0 | #DarkerBackgroundColor#,#NoGradientTransparency# ; 1.0"]

TextBoxTrueAction=[!SetOptionGroup TextBoxGroup SolidColor #DarkBackgroundColor#]
TextBoxTrueAction2=[!SetOptionGroup TextBoxGroup SolidColor #LightBackgroundColor#]
TextBoxTrueAction3=[!SetOptionGroup TextBoxGroup SolidColor #LightBackgroundColor#]
TextBoxTrueAction4=[!SetOptionGroup TextBoxGroup SolidColor #DarkBackgroundColor#]

TrueAction=#TextTrueAction##BackgroundTrueAction##OpaqueBackgroundTrueAction##TextBoxTrueAction##ImageTrueAction#
TrueAction2=#TextTrueAction2##BackgroundTrueAction2##OpaqueBackgroundTrueAction2##TextBoxTrueAction2##ImageTrueAction2#
TrueAction3=#TextTrueAction3##BackgroundTrueAction3##OpaqueBackgroundTrueAction3##TextBoxTrueAction3##ImageTrueAction3#
TrueAction4=#TextTrueAction4##BackgroundTrueAction4##OpaqueBackgroundTrueAction4##TextBoxTrueAction4##ImageTrueAction4#

[measureGradient]
Measure=Calc
DynamicVariables=1
Formula=#Gradient#

[measureLightMode]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Software\Microsoft\Windows\CurrentVersion\Themes\Personalize
RegValue=AppsUseLightTheme
IfCondition=(measureLightMode = 0) && (measureGradient = 1)
IfCondition2=(measureLightMode = 1) && (measureGradient = 0)
IfCondition3=(measureLightMode = 1) && (measureGradient = 1)
IfCondition4=(measureLightMode = 0) && (measureGradient = 0)
IfTrueAction=#TrueAction#
IfTrueAction2=#TrueAction2#
IfTrueAction3=#TrueAction3#
IfTrueAction4=#TrueAction4#

[measureDocsFolder]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders
RegValue=Personal
