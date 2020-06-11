#!/bin/bash

#dotnet build -c Debug
scp -r bin/debug/netcoreapp3.1/* daeken@10.0.0.39:HvTest/ >/dev/null
ssh daeken@10.0.0.39 'cd HvTest; dotnet HvTest.dll'
