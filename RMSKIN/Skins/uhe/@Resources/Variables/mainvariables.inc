;these variables are the design building blocks of skins (i.e. these shouldn't be changed unless there's a significant design change)
;also contains measures that uses these values
[Rainmeter]
AccurateText=1
DynamicWindowSize=1
ContextTitle="Edit main variables"
ContextAction=["#SKINSPATH#\uhe\@Resources\Variables\mainvariables.inc"]
@Include=uservariables.inc
@Include3=formattingvariables.inc
@Include4=easingvariables.inc
Group=AllSkins

[Variables]
CurrentVersion=v1.4.1

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

DarkBackgroundColor=70,70,70
DarkerBackgroundColor=0,0,0

LightBackgroundColor=185,185,185
LighterBackgroundColor=255,255,255

ClickableTransparentColor=0,0,0,1

BarBackgroundColor=#DarkerBackgroundColor#,#NoGradientTransparency#
OpaqueBarBackgroundColor=#DarkBackgroundColor#,#NoGradientTransparency#

DarkFontColor=255,255,255
LightFontColor=0,0,0

PoorFontSize=10

SidePadding=10

CornerRadius=10

PaddingSize=#SidePadding#,#SidePadding#,#SidePadding#,#SidePadding#

; samples taken from
; - https://mixkit.co/free-sound-effects/interface/
; - https://mixkit.co/free-sound-effects/typewriter/
PlayButtonClick=[Play "#SKINSPATH#/uhe/@Resources/Samples/button-click.wav"]
TypewriterPress=[Play "#SKINSPATH#/uhe/@Resources/Samples/typewriter-press.wav"]

SetDarkModeGradient=[!SetOptionGroup TextGroup FontColor #DarkFontColor#][!SetOptionGroup BackgroundGroup Gradient "180 | #DarkBackgroundColor#,#GradientHigh# ; 0.0 | #DarkBackgroundColor#,#GradientLow# ; 1.0"][!SetOptionGroup OpaqueBackgroundGroup Gradient "180 | #DarkerBackgroundColor#,#GradientHigh# ; 0.0 | #DarkerBackgroundColor#,#GradientLow# ; 1.0"][!SetOptionGroup TextBoxGroup SolidColor #DarkBackgroundColor#][!SetOptionGroup SpriteGroup ImageTint #DarkFontColor#]
SetLightMode=[!SetOptionGroup TextGroup FontColor #LightFontColor#][!SetOptionGroup BackgroundGroup Gradient "180 | #LightBackgroundColor#,#NoGradientTransparency# ; 0.0 | #LightBackgroundColor#,#NoGradientTransparency# ; 1.0"][!SetOptionGroup OpaqueBackgroundGroup Gradient "180 | #LighterBackgroundColor#,#NoGradientTransparency# ; 0.0 | #LighterBackgroundColor#,#NoGradientTransparency# ; 1.0"][!SetOptionGroup TextBoxGroup SolidColor #LightBackgroundColor#][!SetOptionGroup SpriteGroup ImageTint #LightFontColor#]
SetLightModeGradient=[!SetOptionGroup TextGroup FontColor #LightFontColor#][!SetOptionGroup BackgroundGroup Gradient "180 | #LightBackgroundColor#,#GradientHigh# ; 0.0 | #LightBackgroundColor#,#GradientLow# ; 1.0"][!SetOptionGroup OpaqueBackgroundGroup Gradient "180 | #LighterBackgroundColor#,#GradientHigh# ; 0.0 | #LighterBackgroundColor#,#GradientLow# ; 1.0"][!SetOptionGroup TextBoxGroup SolidColor #LightBackgroundColor#][!SetOptionGroup SpriteGroup ImageTint #LightFontColor#]
SetDarkMode=[!SetOptionGroup TextGroup FontColor #DarkFontColor#][!SetOptionGroup BackgroundGroup Gradient "180 | #DarkBackgroundColor#,#NoGradientTransparency# ; 0.0 | #DarkBackgroundColor#,#NoGradientTransparency# ; 1.0"][!SetOptionGroup OpaqueBackgroundGroup Gradient "180 | #DarkerBackgroundColor#,#NoGradientTransparency# ; 0.0 | #DarkerBackgroundColor#,#NoGradientTransparency# ; 1.0"][!SetOptionGroup TextBoxGroup SolidColor #DarkBackgroundColor#][!SetOptionGroup SpriteGroup ImageTint #DarkFontColor#]

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
IfTrueAction=#SetDarkModeGradient#
IfTrueAction2=#SetLightMode#
IfTrueAction3=#SetLightModeGradient#
IfTrueAction4=#SetDarkMode#

[measureDocsFolder]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders
RegValue=Personal
