

mkdir install-prefix

cmake --preset=default -DCMAKE_BUILD_TYPE=RELEASE .. 2>&1 | Tee-Object -FilePath configure.log

cmake --build . 2>&1 | Tee-Object -FilePath build.log

cmake --install . --prefix "$(pwd)/install-prefix" 2>&1 | Tee-Object -FilePath ./install.log
