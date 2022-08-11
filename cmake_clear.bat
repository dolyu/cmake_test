echo "clean cmake cache begin..."

echo "rm ./build.dir"
rm -rf ./build

echo "rm ./CMakeFiles"
rm -rf ./CMakeFiles

echo "rm ./cmake_install.cmake"
rm ./cmake_install.cmake

echo "rm ./Makefile"
rm ./Makefile

echo "rm ./Makefile.tmp"
rm ./Makefile.tmp

echo "rm ./CMakeCache.txt"
rm ./CMakeCache.txt

echo "rm ./*.cmake"
rm ./*.cmake

echo "rm ./install_manifest.txt"
rm ./install_manifest.txt

echo "clean cmake cache end."
