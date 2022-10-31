[Rainmeter]
ContextTitle3="Edit osu! variables"
ContextAction3=["#@#Variables/osuvariables.inc"]

[Variables]
Username=Joehu
UserID=8549835
HostName=https://osu.ppy.sh/api/v2
Mode=osu

[measureToken]
Measure=Plugin
Plugin=RunCommand
Parameter=curl -s -d "client_id=#OsuClientID#&client_secret=#OsuClientSecret#&grant_type=client_credentials&scope=public" -X POST "https://osu.ppy.sh/oauth/token"
UpdateDivider=-1
OutputType=ANSI
RegExpSubstitute=1
Substitute='.*"access_token":"(.+)"}':"\1"
FinishAction=[!WriteKeyValue Variables OsuToken [measureToken] "#@#Variables/apivariables.inc"][!RefreshGroup osu]
