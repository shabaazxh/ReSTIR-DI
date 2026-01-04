# ReSTIR-DI
A Vulkan renderer implementing the Reservoir-based Spatio-Temporal Importance Resampling algorithm; written as part of MSc thesis


## Building
### Windows
```bash
./premake5 vs2022
```

### Linux
```bash
./premake5 gmake2
make
./bin/Engine-release-x64-gcc.exe
```

<p align="center">
  <img src="showcase/no_restir.png" width="700"><br>
  <em>RIS using WRS</em><br><br>

  <img src="showcase/biased_restir.png" width="700"><br>
  <em>Biased ReSTIR</em><br><br>

  <img src="showcase/unbiased_restir.png" width="700"><br>
  <em>Unbiased ReSTIR</em>
</p>


## Assets
Find the Sponza GLTF https://github.com/KhronosGroup/glTF-Sample-Assets/tree/main/Models/Sponza

[Sponza] (https://github.com/KhronosGroup/glTF-Sample-Assets/tree/main/Models/Sponza) GLTF

