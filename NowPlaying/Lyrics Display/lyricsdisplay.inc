[Rainmeter]
@Include=#@#Variables/mainvariables.inc
ContextTitle2="Edit base lyrics display"
ContextAction2=["#CURRENTPATH#lyricsdisplay.inc"]

[Variables]
CurrentY=0
ScrollDistance=40
ScrollbarWidth=5

[measureLyrics]
Measure=NowPlaying
PlayerType=Lyrics
IfMatch=(.+)
IfMatchAction=[!SetOption meterLyrics Text "%1"]
;[!ShowMeter meterLyricsContainer][!ShowMeter meterLyricsContainerVisible]
IfNotMatchAction=[!SetOption meterLyrics Text "No lyrics found..."]
;[!HideMeter meterLyricsContainer][!HideMeter meterLyricsContainerVisible]
OnChangeAction=[!Update][!SetVariable CurrentY 0][!UpdateMeasure measureScrollbarHeight]

[measureScrollbarHeight]
Measure=Calc
DynamicVariables=1
Formula=(Min((([meterLyricsContainer:H] / [meterLyrics:H]) * [meterLyricsContainer:H]), [meterLyricsContainer:H]))
IfCondition=measureScrollbarHeight = [meterLyricsContainer:H]
IfTrueAction=[!HideMeter meterScrollbar][!Redraw]
IfFalseAction=[!ShowMeter meterScrollbar][!Redraw]

[meterLyricsTitleBackground]
Meter=Shape
Shape=Rectangle 0,0,[meterLyricsTitle:W],[meterLyricsTitle:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=BackgroundGroup

[meterLyricsTitle]
Meter=String
DynamicVariables=1
W=([meterLyrics:W] - (#SidePadding# * 2))
Text=Lyrics
AntiAlias=1
FontFace=#DisplayFont#
FontSize=22
Padding=#PaddingSize#
Group=TextGroup

[meterLyricsContainerVisible]
Meter=Shape
Shape=Rectangle 0,0,[meterLyricsContainer:W],[meterLyricsContainer:H],#CornerRadius# | Fill LinearGradient Gradient | StrokeWidth 0
;add placeholder option to hide errors
Gradient=0 | 0,0,0,0 ; 0.0
DynamicVariables=1
Group=OpaqueBackgroundGroup
Y=R

[meterLyricsContainer]
Meter=Image
H=(#wORKAREAHEIGHT# / 2)
Y=r
W=250
Padding=#PaddingSize#
SolidColor=0,0,0
DynamicVariables=1
MouseScrollDownAction=[!SetVariable CurrentY "(Clamp((#CurrentY# - #ScrollDistance#),(-(Max([meterLyrics:H]-[meterLyricsContainer:H],0))),0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable CurrentY "(Clamp((#CurrentY# + #ScrollDistance#),(-(Max([meterLyrics:H]-[meterLyricsContainer:H],0))),0))"][!UpdateMeter *][!Redraw]

[meterLyrics]
Meter=String
MeasureName=measureLyrics
AntiAlias=1
FontFace=#FontFace#
FontSize=10
Padding=#PaddingSize#
W=250
ClipString=2
Group=TextGroup
Container=meterLyricsContainer
DynamicVariables=1
Y=#CurrentY#

[meterScrollbarContainer]
Meter=Shape
Shape=Rectangle 0,0,(#SidePadding#*2),[meterLyricsContainer:H],#CornerRadius# | StrokeWidth 0
DynamicVariables=1
X=(-#SidePadding#*2)R
Y=r

[meterScrollbar]
Meter=Image
DynamicVariables=1
Y=(([meterLyricsContainer:H]-[meterScrollbar:H]) * (-#CurrentY# / ([meterLyrics:H]-[meterLyricsContainer:H])))r
W=#ScrollbarWidth#
X=([meterScrollbarContainer:W] - #ScrollbarWidth#)
H=[measureScrollbarHeight]
SolidColor=#LightHighlight#
Container=meterScrollbarContainer
