$folders = @("friend", "initialization", "user", "input", "save_load", "utas", "tweet_draft", "reply", "tweet", "friend_request", "profile")

foreach ($folder in $folders) {
    New-Item  -Name "driver_$folder.c" -ItemType File
}
