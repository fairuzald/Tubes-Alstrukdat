$folders = @("friend", "initialization", "user", "input", "save_load", "utas", "tweet_draft", "reply", "tweet", "friend_request", "profile")

foreach ($folder in $folders) {
    $filename = $folder + "_driver.c"
    New-Item -Path $filename -ItemType File
}
