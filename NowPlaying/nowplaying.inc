[Rainmeter]
@Include=#@#Variables/mainvariables.inc
ContextTitle2="Edit base now playing"
ContextAction2=["#CURRENTPATH#nowplaying.inc"]
Group=RelativeToScreenWidth | AllSkins

[Variables]
icon=[\xf001]

[measureArtist]
Measure=NowPlaying
PlayerType=Artist

[measureTitle]
Measure=NowPlaying
PlayerType=Title

[meterBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterMiddle:W],[meterMiddle:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup

[meterMiddle]
Meter=String
MeasureName=measureArtist
MeasureName2=measureTitle
AntiAlias=1
FontFace=#FontFace#
FontSize=20
H=40
Y=([meterMiddle:H] / 2)
Padding=#PaddingSize#
StringAlign=LeftCenter
InlineSetting=Face | #IconFace#
InlinePattern=#icon#
Text=#icon# | %1 - %2
ClipString=1
Group=TextGroup
