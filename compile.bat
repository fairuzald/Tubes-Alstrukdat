@echo off
for /R %%G in (*.c) do (
    if not "%%~dpG"=="%CD%\driver\" (
        if not "%%~dpG"=="%CD%\.vscode\" (
            if not "%%~dpG"=="%CD%\.github\" (
                if not "%%~dpG"=="%CD%\config\" (
                    echo Compiling %%G
                    gcc -o "%%~nG.exe" "%%G"
                )
            )
        )
    )
)
