#include "RandomGenerator.h"
#include "../FastNoiseLite.h"
#include "../PerlinNoise.hpp"
#include <iostream>

// do not use this one to your assignment. this is my sample generator
std::vector<Color32> RandomScenarioGenerator::Generate(int sideSize, float displacement) {
  std::vector<Color32> colors;

//   create your own function for noise generation
  FastNoiseLite base;
  base.SetFractalOctaves(3);
  base.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
  base.SetFractalType(FastNoiseLite::FractalType_FBm);

  FastNoiseLite cellular;
  cellular.SetNoiseType(FastNoiseLite::NoiseType_Cellular);
  cellular.SetFractalOctaves(3);

  FastNoiseLite ridge;
  ridge.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2S);
  ridge.SetFractalType(FastNoiseLite::FractalType_Ridged);

  siv::BasicPerlinNoise<float> noise;
  noise.reseed(1337);

  for(int y=0; y<sideSize; y++)
  {
    for(int x=0;x<sideSize; x++)
    {
      float detail = 2;

      float c1 = ((base.GetNoise((float)x ,(float)y, displacement * 50) +1 ) / 2) *255;
      float c2 = ((cellular.GetNoise((float)x ,(float)y , displacement * 50) +1 ) / 2) *255;

      //////Quincy Code   

      float rig = ((ridge.GetNoise((float)x * detail, (float)y * detail, displacement * 50) + 1) / 2) * 255;

      //float t = 1 * ridge.GetNoise((float)x * 1, (float)y * 1, displacement);
      //float t2 = .5 * ridge.GetNoise((float)x * 2, (float)y * 2, displacement) * t;
      //float t3 = .25 * ridge.GetNoise((float)x * 4, (float)y * 4, displacement * 50) * (t + t2);

      //float e = (t + t2 + t3) / (1 + .5 + .25);


      auto rgb = (c1 + c2 + rig) / 2;
      //auto rgb = (c1 + c2) / 2 ;
      //std::cout << e << " This is rig QUINCY" << std::endl;
       //std::cout << c1 << " This is C1 QUINCY" << std::endl;
       //std::cout << c2 << " This is C2 QUINCY" << std::endl;
       //std::cout << rgb << " This is rgb QUINCY" << std::endl;
 

      //47-103
      //water
      if (rgb < 135) {
        colors.emplace_back(0, 0, 255);
      }
      //grass
      else if (rgb < 165) {
        colors.emplace_back(0, 100, 0);
      }
      //hills
      else if (rgb < 200) {
        colors.emplace_back(87,  65, 47);
      }
      //Snow Caps
      else 
      {
        colors.emplace_back(255, 255, 255);
      }

      //colors.emplace_back(rgb, rgb, rgb);
    }
  }

  std::cout<<colors.size() << std::endl;
  return colors;
}
std::string RandomScenarioGenerator::GetName() { return "EXAMPLE"; }
