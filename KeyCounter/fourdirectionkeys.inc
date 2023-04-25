[Rainmeter]
@Include=#@#Variables/mainvariables.inc

[measureUpKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Up#
KeyDownAction=[!SetOption meterUpKey SolidColor 192,102,151,100][!UpdateMeter meterUpKey][!Redraw]
KeyUpAction=[!SetOption meterUpKey SolidColor 0,0,0,100][!UpdateMeter meterUpKey][!Redraw]

[measureLeftKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Left#
KeyDownAction=[!SetOption meterLeftKey SolidColor 192,102,151,100][!UpdateMeter meterLeftKey][!Redraw]
KeyUpAction=[!SetOption meterLeftKey SolidColor 0,0,0,100][!UpdateMeter meterLeftKey][!Redraw]

[measureDownKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Down#
KeyDownAction=[!SetOption meterDownKey SolidColor 192,102,151,100][!UpdateMeter meterDownKey][!Redraw]
KeyUpAction=[!SetOption meterDownKey SolidColor 0,0,0,100][!UpdateMeter meterDownKey][!Redraw]

[measureRightKey]
Measure=Plugin
Plugin=HotKey
HotKey=#Right#
KeyDownAction=[!SetOption meterRightKey SolidColor 192,102,151,100][!UpdateMeter meterRightKey][!Redraw]
KeyUpAction=[!SetOption meterRightKey SolidColor 0,0,0,100][!UpdateMeter meterRightKey][!Redraw]

[meterUpKey]
Meter=String
Text=#Up#
StringAlign=CenterCenter
X=150
Y=25
W=100
H=50
FontFace=#FontFace#
FontColor=255,255,255
FontSize=20
AntiAlias=1
SolidColor=0,0,0,100

[meterLeftKey]
Meter=String
Text=#Left#
StringAlign=CenterCenter
X=50
Y=75
W=100
H=50
FontFace=#FontFace#
FontColor=255,255,255
FontSize=20
AntiAlias=1
SolidColor=0,0,0,100

[meterDownKey]
Meter=String
Text=#Down#
StringAlign=CenterCenter
X=R
Y=r
W=100
H=50
FontFace=#FontFace#
FontColor=255,255,255
FontSize=20
AntiAlias=1
SolidColor=0,0,0,100

[meterRightKey]
Meter=String
Text=#Right#
StringAlign=CenterCenter
X=R
Y=r
W=100
H=50
FontFace=#FontFace#
FontColor=255,255,255
FontSize=20
AntiAlias=1
SolidColor=0,0,0,100
