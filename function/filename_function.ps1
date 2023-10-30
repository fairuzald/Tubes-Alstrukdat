$folders = @("friend", "initialization", "user", "input", "save_load", "utas", "tweet_draft", "reply", "tweet", "friend_request", "profile")

foreach ($folder in $folders) {
    New-Item -Path . -Name $folder -ItemType Directory
    New-Item -Path ./$folder -Name "$folder.c" -ItemType File
    New-Item -Path ./$folder -Name "$folder.h" -ItemType File
}
