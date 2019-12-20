const float lut_sine[] = {
   0.000000000e+00,  6.135884649e-03,  1.227153829e-02,  1.840672991e-02,
   2.454122852e-02,  3.067480318e-02,  3.680722294e-02,  4.293825693e-02,
   4.906767433e-02,  5.519524435e-02,  6.132073630e-02,  6.744391956e-02,
   7.356456360e-02,  7.968243797e-02,  8.579731234e-02,  9.190895650e-02,
   9.801714033e-02,  1.041216339e-01,  1.102222073e-01,  1.163186309e-01,
   1.224106752e-01,  1.284981108e-01,  1.345807085e-01,  1.406582393e-01,
   1.467304745e-01,  1.527971853e-01,  1.588581433e-01,  1.649131205e-01,
   1.709618888e-01,  1.770042204e-01,  1.830398880e-01,  1.890686641e-01,
   1.950903220e-01,  2.011046348e-01,  2.071113762e-01,  2.131103199e-01,
   2.191012402e-01,  2.250839114e-01,  2.310581083e-01,  2.370236060e-01,
   2.429801799e-01,  2.489276057e-01,  2.548656596e-01,  2.607941179e-01,
   2.667127575e-01,  2.726213554e-01,  2.785196894e-01,  2.844075372e-01,
   2.902846773e-01,  2.961508882e-01,  3.020059493e-01,  3.078496400e-01,
   3.136817404e-01,  3.195020308e-01,  3.253102922e-01,  3.311063058e-01,
   3.368898534e-01,  3.426607173e-01,  3.484186802e-01,  3.541635254e-01,
   3.598950365e-01,  3.656129978e-01,  3.713171940e-01,  3.770074102e-01,
   3.826834324e-01,  3.883450467e-01,  3.939920401e-01,  3.996241998e-01,
   4.052413140e-01,  4.108431711e-01,  4.164295601e-01,  4.220002708e-01,
   4.275550934e-01,  4.330938189e-01,  4.386162385e-01,  4.441221446e-01,
   4.496113297e-01,  4.550835871e-01,  4.605387110e-01,  4.659764958e-01,
   4.713967368e-01,  4.767992301e-01,  4.821837721e-01,  4.875501601e-01,
   4.928981922e-01,  4.982276670e-01,  5.035383837e-01,  5.088301425e-01,
   5.141027442e-01,  5.193559902e-01,  5.245896827e-01,  5.298036247e-01,
   5.349976199e-01,  5.401714727e-01,  5.453249884e-01,  5.504579729e-01,
   5.555702330e-01,  5.606615762e-01,  5.657318108e-01,  5.707807459e-01,
   5.758081914e-01,  5.808139581e-01,  5.857978575e-01,  5.907597019e-01,
   5.956993045e-01,  6.006164794e-01,  6.055110414e-01,  6.103828063e-01,
   6.152315906e-01,  6.200572118e-01,  6.248594881e-01,  6.296382389e-01,
   6.343932842e-01,  6.391244449e-01,  6.438315429e-01,  6.485144010e-01,
   6.531728430e-01,  6.578066933e-01,  6.624157776e-01,  6.669999223e-01,
   6.715589548e-01,  6.760927036e-01,  6.806009978e-01,  6.850836678e-01,
   6.895405447e-01,  6.939714609e-01,  6.983762494e-01,  7.027547445e-01,
   7.071067812e-01,  7.114321957e-01,  7.157308253e-01,  7.200025080e-01,
   7.242470830e-01,  7.284643904e-01,  7.326542717e-01,  7.368165689e-01,
   7.409511254e-01,  7.450577854e-01,  7.491363945e-01,  7.531867990e-01,
   7.572088465e-01,  7.612023855e-01,  7.651672656e-01,  7.691033376e-01,
   7.730104534e-01,  7.768884657e-01,  7.807372286e-01,  7.845565972e-01,
   7.883464276e-01,  7.921065773e-01,  7.958369046e-01,  7.995372691e-01,
   8.032075315e-01,  8.068475535e-01,  8.104571983e-01,  8.140363297e-01,
   8.175848132e-01,  8.211025150e-01,  8.245893028e-01,  8.280450453e-01,
   8.314696123e-01,  8.348628750e-01,  8.382247056e-01,  8.415549774e-01,
   8.448535652e-01,  8.481203448e-01,  8.513551931e-01,  8.545579884e-01,
   8.577286100e-01,  8.608669386e-01,  8.639728561e-01,  8.670462455e-01,
   8.700869911e-01,  8.730949784e-01,  8.760700942e-01,  8.790122264e-01,
   8.819212643e-01,  8.847970984e-01,  8.876396204e-01,  8.904487232e-01,
   8.932243012e-01,  8.959662498e-01,  8.986744657e-01,  9.013488470e-01,
   9.039892931e-01,  9.065957045e-01,  9.091679831e-01,  9.117060320e-01,
   9.142097557e-01,  9.166790599e-01,  9.191138517e-01,  9.215140393e-01,
   9.238795325e-01,  9.262102421e-01,  9.285060805e-01,  9.307669611e-01,
   9.329927988e-01,  9.351835099e-01,  9.373390119e-01,  9.394592236e-01,
   9.415440652e-01,  9.435934582e-01,  9.456073254e-01,  9.475855910e-01,
   9.495281806e-01,  9.514350210e-01,  9.533060404e-01,  9.551411683e-01,
   9.569403357e-01,  9.587034749e-01,  9.604305194e-01,  9.621214043e-01,
   9.637760658e-01,  9.653944417e-01,  9.669764710e-01,  9.685220943e-01,
   9.700312532e-01,  9.715038910e-01,  9.729399522e-01,  9.743393828e-01,
   9.757021300e-01,  9.770281427e-01,  9.783173707e-01,  9.795697657e-01,
   9.807852804e-01,  9.819638691e-01,  9.831054874e-01,  9.842100924e-01,
   9.852776424e-01,  9.863080972e-01,  9.873014182e-01,  9.882575677e-01,
   9.891765100e-01,  9.900582103e-01,  9.909026354e-01,  9.917097537e-01,
   9.924795346e-01,  9.932119492e-01,  9.939069700e-01,  9.945645707e-01,
   9.951847267e-01,  9.957674145e-01,  9.963126122e-01,  9.968202993e-01,
   9.972904567e-01,  9.977230666e-01,  9.981181129e-01,  9.984755806e-01,
   9.987954562e-01,  9.990777278e-01,  9.993223846e-01,  9.995294175e-01,
   9.996988187e-01,  9.998305818e-01,  9.999247018e-01,  9.999811753e-01,
   1.000000000e+00,  9.999811753e-01,  9.999247018e-01,  9.998305818e-01,
   9.996988187e-01,  9.995294175e-01,  9.993223846e-01,  9.990777278e-01,
   9.987954562e-01,  9.984755806e-01,  9.981181129e-01,  9.977230666e-01,
   9.972904567e-01,  9.968202993e-01,  9.963126122e-01,  9.957674145e-01,
   9.951847267e-01,  9.945645707e-01,  9.939069700e-01,  9.932119492e-01,
   9.924795346e-01,  9.917097537e-01,  9.909026354e-01,  9.900582103e-01,
   9.891765100e-01,  9.882575677e-01,  9.873014182e-01,  9.863080972e-01,
   9.852776424e-01,  9.842100924e-01,  9.831054874e-01,  9.819638691e-01,
   9.807852804e-01,  9.795697657e-01,  9.783173707e-01,  9.770281427e-01,
   9.757021300e-01,  9.743393828e-01,  9.729399522e-01,  9.715038910e-01,
   9.700312532e-01,  9.685220943e-01,  9.669764710e-01,  9.653944417e-01,
   9.637760658e-01,  9.621214043e-01,  9.604305194e-01,  9.587034749e-01,
   9.569403357e-01,  9.551411683e-01,  9.533060404e-01,  9.514350210e-01,
   9.495281806e-01,  9.475855910e-01,  9.456073254e-01,  9.435934582e-01,
   9.415440652e-01,  9.394592236e-01,  9.373390119e-01,  9.351835099e-01,
   9.329927988e-01,  9.307669611e-01,  9.285060805e-01,  9.262102421e-01,
   9.238795325e-01,  9.215140393e-01,  9.191138517e-01,  9.166790599e-01,
   9.142097557e-01,  9.117060320e-01,  9.091679831e-01,  9.065957045e-01,
   9.039892931e-01,  9.013488470e-01,  8.986744657e-01,  8.959662498e-01,
   8.932243012e-01,  8.904487232e-01,  8.876396204e-01,  8.847970984e-01,
   8.819212643e-01,  8.790122264e-01,  8.760700942e-01,  8.730949784e-01,
   8.700869911e-01,  8.670462455e-01,  8.639728561e-01,  8.608669386e-01,
   8.577286100e-01,  8.545579884e-01,  8.513551931e-01,  8.481203448e-01,
   8.448535652e-01,  8.415549774e-01,  8.382247056e-01,  8.348628750e-01,
   8.314696123e-01,  8.280450453e-01,  8.245893028e-01,  8.211025150e-01,
   8.175848132e-01,  8.140363297e-01,  8.104571983e-01,  8.068475535e-01,
   8.032075315e-01,  7.995372691e-01,  7.958369046e-01,  7.921065773e-01,
   7.883464276e-01,  7.845565972e-01,  7.807372286e-01,  7.768884657e-01,
   7.730104534e-01,  7.691033376e-01,  7.651672656e-01,  7.612023855e-01,
   7.572088465e-01,  7.531867990e-01,  7.491363945e-01,  7.450577854e-01,
   7.409511254e-01,  7.368165689e-01,  7.326542717e-01,  7.284643904e-01,
   7.242470830e-01,  7.200025080e-01,  7.157308253e-01,  7.114321957e-01,
   7.071067812e-01,  7.027547445e-01,  6.983762494e-01,  6.939714609e-01,
   6.895405447e-01,  6.850836678e-01,  6.806009978e-01,  6.760927036e-01,
   6.715589548e-01,  6.669999223e-01,  6.624157776e-01,  6.578066933e-01,
   6.531728430e-01,  6.485144010e-01,  6.438315429e-01,  6.391244449e-01,
   6.343932842e-01,  6.296382389e-01,  6.248594881e-01,  6.200572118e-01,
   6.152315906e-01,  6.103828063e-01,  6.055110414e-01,  6.006164794e-01,
   5.956993045e-01,  5.907597019e-01,  5.857978575e-01,  5.808139581e-01,
   5.758081914e-01,  5.707807459e-01,  5.657318108e-01,  5.606615762e-01,
   5.555702330e-01,  5.504579729e-01,  5.453249884e-01,  5.401714727e-01,
   5.349976199e-01,  5.298036247e-01,  5.245896827e-01,  5.193559902e-01,
   5.141027442e-01,  5.088301425e-01,  5.035383837e-01,  4.982276670e-01,
   4.928981922e-01,  4.875501601e-01,  4.821837721e-01,  4.767992301e-01,
   4.713967368e-01,  4.659764958e-01,  4.605387110e-01,  4.550835871e-01,
   4.496113297e-01,  4.441221446e-01,  4.386162385e-01,  4.330938189e-01,
   4.275550934e-01,  4.220002708e-01,  4.164295601e-01,  4.108431711e-01,
   4.052413140e-01,  3.996241998e-01,  3.939920401e-01,  3.883450467e-01,
   3.826834324e-01,  3.770074102e-01,  3.713171940e-01,  3.656129978e-01,
   3.598950365e-01,  3.541635254e-01,  3.484186802e-01,  3.426607173e-01,
   3.368898534e-01,  3.311063058e-01,  3.253102922e-01,  3.195020308e-01,
   3.136817404e-01,  3.078496400e-01,  3.020059493e-01,  2.961508882e-01,
   2.902846773e-01,  2.844075372e-01,  2.785196894e-01,  2.726213554e-01,
   2.667127575e-01,  2.607941179e-01,  2.548656596e-01,  2.489276057e-01,
   2.429801799e-01,  2.370236060e-01,  2.310581083e-01,  2.250839114e-01,
   2.191012402e-01,  2.131103199e-01,  2.071113762e-01,  2.011046348e-01,
   1.950903220e-01,  1.890686641e-01,  1.830398880e-01,  1.770042204e-01,
   1.709618888e-01,  1.649131205e-01,  1.588581433e-01,  1.527971853e-01,
   1.467304745e-01,  1.406582393e-01,  1.345807085e-01,  1.284981108e-01,
   1.224106752e-01,  1.163186309e-01,  1.102222073e-01,  1.041216339e-01,
   9.801714033e-02,  9.190895650e-02,  8.579731234e-02,  7.968243797e-02,
   7.356456360e-02,  6.744391956e-02,  6.132073630e-02,  5.519524435e-02,
   4.906767433e-02,  4.293825693e-02,  3.680722294e-02,  3.067480318e-02,
   2.454122852e-02,  1.840672991e-02,  1.227153829e-02,  6.135884649e-03,
   1.224646799e-16, -6.135884649e-03, -1.227153829e-02, -1.840672991e-02,
  -2.454122852e-02, -3.067480318e-02, -3.680722294e-02, -4.293825693e-02,
  -4.906767433e-02, -5.519524435e-02, -6.132073630e-02, -6.744391956e-02,
  -7.356456360e-02, -7.968243797e-02, -8.579731234e-02, -9.190895650e-02,
  -9.801714033e-02, -1.041216339e-01, -1.102222073e-01, -1.163186309e-01,
  -1.224106752e-01, -1.284981108e-01, -1.345807085e-01, -1.406582393e-01,
  -1.467304745e-01, -1.527971853e-01, -1.588581433e-01, -1.649131205e-01,
  -1.709618888e-01, -1.770042204e-01, -1.830398880e-01, -1.890686641e-01,
  -1.950903220e-01, -2.011046348e-01, -2.071113762e-01, -2.131103199e-01,
  -2.191012402e-01, -2.250839114e-01, -2.310581083e-01, -2.370236060e-01,
  -2.429801799e-01, -2.489276057e-01, -2.548656596e-01, -2.607941179e-01,
  -2.667127575e-01, -2.726213554e-01, -2.785196894e-01, -2.844075372e-01,
  -2.902846773e-01, -2.961508882e-01, -3.020059493e-01, -3.078496400e-01,
  -3.136817404e-01, -3.195020308e-01, -3.253102922e-01, -3.311063058e-01,
  -3.368898534e-01, -3.426607173e-01, -3.484186802e-01, -3.541635254e-01,
  -3.598950365e-01, -3.656129978e-01, -3.713171940e-01, -3.770074102e-01,
  -3.826834324e-01, -3.883450467e-01, -3.939920401e-01, -3.996241998e-01,
  -4.052413140e-01, -4.108431711e-01, -4.164295601e-01, -4.220002708e-01,
  -4.275550934e-01, -4.330938189e-01, -4.386162385e-01, -4.441221446e-01,
  -4.496113297e-01, -4.550835871e-01, -4.605387110e-01, -4.659764958e-01,
  -4.713967368e-01, -4.767992301e-01, -4.821837721e-01, -4.875501601e-01,
  -4.928981922e-01, -4.982276670e-01, -5.035383837e-01, -5.088301425e-01,
  -5.141027442e-01, -5.193559902e-01, -5.245896827e-01, -5.298036247e-01,
  -5.349976199e-01, -5.401714727e-01, -5.453249884e-01, -5.504579729e-01,
  -5.555702330e-01, -5.606615762e-01, -5.657318108e-01, -5.707807459e-01,
  -5.758081914e-01, -5.808139581e-01, -5.857978575e-01, -5.907597019e-01,
  -5.956993045e-01, -6.006164794e-01, -6.055110414e-01, -6.103828063e-01,
  -6.152315906e-01, -6.200572118e-01, -6.248594881e-01, -6.296382389e-01,
  -6.343932842e-01, -6.391244449e-01, -6.438315429e-01, -6.485144010e-01,
  -6.531728430e-01, -6.578066933e-01, -6.624157776e-01, -6.669999223e-01,
  -6.715589548e-01, -6.760927036e-01, -6.806009978e-01, -6.850836678e-01,
  -6.895405447e-01, -6.939714609e-01, -6.983762494e-01, -7.027547445e-01,
  -7.071067812e-01, -7.114321957e-01, -7.157308253e-01, -7.200025080e-01,
  -7.242470830e-01, -7.284643904e-01, -7.326542717e-01, -7.368165689e-01,
  -7.409511254e-01, -7.450577854e-01, -7.491363945e-01, -7.531867990e-01,
  -7.572088465e-01, -7.612023855e-01, -7.651672656e-01, -7.691033376e-01,
  -7.730104534e-01, -7.768884657e-01, -7.807372286e-01, -7.845565972e-01,
  -7.883464276e-01, -7.921065773e-01, -7.958369046e-01, -7.995372691e-01,
  -8.032075315e-01, -8.068475535e-01, -8.104571983e-01, -8.140363297e-01,
  -8.175848132e-01, -8.211025150e-01, -8.245893028e-01, -8.280450453e-01,
  -8.314696123e-01, -8.348628750e-01, -8.382247056e-01, -8.415549774e-01,
  -8.448535652e-01, -8.481203448e-01, -8.513551931e-01, -8.545579884e-01,
  -8.577286100e-01, -8.608669386e-01, -8.639728561e-01, -8.670462455e-01,
  -8.700869911e-01, -8.730949784e-01, -8.760700942e-01, -8.790122264e-01,
  -8.819212643e-01, -8.847970984e-01, -8.876396204e-01, -8.904487232e-01,
  -8.932243012e-01, -8.959662498e-01, -8.986744657e-01, -9.013488470e-01,
  -9.039892931e-01, -9.065957045e-01, -9.091679831e-01, -9.117060320e-01,
  -9.142097557e-01, -9.166790599e-01, -9.191138517e-01, -9.215140393e-01,
  -9.238795325e-01, -9.262102421e-01, -9.285060805e-01, -9.307669611e-01,
  -9.329927988e-01, -9.351835099e-01, -9.373390119e-01, -9.394592236e-01,
  -9.415440652e-01, -9.435934582e-01, -9.456073254e-01, -9.475855910e-01,
  -9.495281806e-01, -9.514350210e-01, -9.533060404e-01, -9.551411683e-01,
  -9.569403357e-01, -9.587034749e-01, -9.604305194e-01, -9.621214043e-01,
  -9.637760658e-01, -9.653944417e-01, -9.669764710e-01, -9.685220943e-01,
  -9.700312532e-01, -9.715038910e-01, -9.729399522e-01, -9.743393828e-01,
  -9.757021300e-01, -9.770281427e-01, -9.783173707e-01, -9.795697657e-01,
  -9.807852804e-01, -9.819638691e-01, -9.831054874e-01, -9.842100924e-01,
  -9.852776424e-01, -9.863080972e-01, -9.873014182e-01, -9.882575677e-01,
  -9.891765100e-01, -9.900582103e-01, -9.909026354e-01, -9.917097537e-01,
  -9.924795346e-01, -9.932119492e-01, -9.939069700e-01, -9.945645707e-01,
  -9.951847267e-01, -9.957674145e-01, -9.963126122e-01, -9.968202993e-01,
  -9.972904567e-01, -9.977230666e-01, -9.981181129e-01, -9.984755806e-01,
  -9.987954562e-01, -9.990777278e-01, -9.993223846e-01, -9.995294175e-01,
  -9.996988187e-01, -9.998305818e-01, -9.999247018e-01, -9.999811753e-01,
  -1.000000000e+00, -9.999811753e-01, -9.999247018e-01, -9.998305818e-01,
  -9.996988187e-01, -9.995294175e-01, -9.993223846e-01, -9.990777278e-01,
  -9.987954562e-01, -9.984755806e-01, -9.981181129e-01, -9.977230666e-01,
  -9.972904567e-01, -9.968202993e-01, -9.963126122e-01, -9.957674145e-01,
  -9.951847267e-01, -9.945645707e-01, -9.939069700e-01, -9.932119492e-01,
  -9.924795346e-01, -9.917097537e-01, -9.909026354e-01, -9.900582103e-01,
  -9.891765100e-01, -9.882575677e-01, -9.873014182e-01, -9.863080972e-01,
  -9.852776424e-01, -9.842100924e-01, -9.831054874e-01, -9.819638691e-01,
  -9.807852804e-01, -9.795697657e-01, -9.783173707e-01, -9.770281427e-01,
  -9.757021300e-01, -9.743393828e-01, -9.729399522e-01, -9.715038910e-01,
  -9.700312532e-01, -9.685220943e-01, -9.669764710e-01, -9.653944417e-01,
  -9.637760658e-01, -9.621214043e-01, -9.604305194e-01, -9.587034749e-01,
  -9.569403357e-01, -9.551411683e-01, -9.533060404e-01, -9.514350210e-01,
  -9.495281806e-01, -9.475855910e-01, -9.456073254e-01, -9.435934582e-01,
  -9.415440652e-01, -9.394592236e-01, -9.373390119e-01, -9.351835099e-01,
  -9.329927988e-01, -9.307669611e-01, -9.285060805e-01, -9.262102421e-01,
  -9.238795325e-01, -9.215140393e-01, -9.191138517e-01, -9.166790599e-01,
  -9.142097557e-01, -9.117060320e-01, -9.091679831e-01, -9.065957045e-01,
  -9.039892931e-01, -9.013488470e-01, -8.986744657e-01, -8.959662498e-01,
  -8.932243012e-01, -8.904487232e-01, -8.876396204e-01, -8.847970984e-01,
  -8.819212643e-01, -8.790122264e-01, -8.760700942e-01, -8.730949784e-01,
  -8.700869911e-01, -8.670462455e-01, -8.639728561e-01, -8.608669386e-01,
  -8.577286100e-01, -8.545579884e-01, -8.513551931e-01, -8.481203448e-01,
  -8.448535652e-01, -8.415549774e-01, -8.382247056e-01, -8.348628750e-01,
  -8.314696123e-01, -8.280450453e-01, -8.245893028e-01, -8.211025150e-01,
  -8.175848132e-01, -8.140363297e-01, -8.104571983e-01, -8.068475535e-01,
  -8.032075315e-01, -7.995372691e-01, -7.958369046e-01, -7.921065773e-01,
  -7.883464276e-01, -7.845565972e-01, -7.807372286e-01, -7.768884657e-01,
  -7.730104534e-01, -7.691033376e-01, -7.651672656e-01, -7.612023855e-01,
  -7.572088465e-01, -7.531867990e-01, -7.491363945e-01, -7.450577854e-01,
  -7.409511254e-01, -7.368165689e-01, -7.326542717e-01, -7.284643904e-01,
  -7.242470830e-01, -7.200025080e-01, -7.157308253e-01, -7.114321957e-01,
  -7.071067812e-01, -7.027547445e-01, -6.983762494e-01, -6.939714609e-01,
  -6.895405447e-01, -6.850836678e-01, -6.806009978e-01, -6.760927036e-01,
  -6.715589548e-01, -6.669999223e-01, -6.624157776e-01, -6.578066933e-01,
  -6.531728430e-01, -6.485144010e-01, -6.438315429e-01, -6.391244449e-01,
  -6.343932842e-01, -6.296382389e-01, -6.248594881e-01, -6.200572118e-01,
  -6.152315906e-01, -6.103828063e-01, -6.055110414e-01, -6.006164794e-01,
  -5.956993045e-01, -5.907597019e-01, -5.857978575e-01, -5.808139581e-01,
  -5.758081914e-01, -5.707807459e-01, -5.657318108e-01, -5.606615762e-01,
  -5.555702330e-01, -5.504579729e-01, -5.453249884e-01, -5.401714727e-01,
  -5.349976199e-01, -5.298036247e-01, -5.245896827e-01, -5.193559902e-01,
  -5.141027442e-01, -5.088301425e-01, -5.035383837e-01, -4.982276670e-01,
  -4.928981922e-01, -4.875501601e-01, -4.821837721e-01, -4.767992301e-01,
  -4.713967368e-01, -4.659764958e-01, -4.605387110e-01, -4.550835871e-01,
  -4.496113297e-01, -4.441221446e-01, -4.386162385e-01, -4.330938189e-01,
  -4.275550934e-01, -4.220002708e-01, -4.164295601e-01, -4.108431711e-01,
  -4.052413140e-01, -3.996241998e-01, -3.939920401e-01, -3.883450467e-01,
  -3.826834324e-01, -3.770074102e-01, -3.713171940e-01, -3.656129978e-01,
  -3.598950365e-01, -3.541635254e-01, -3.484186802e-01, -3.426607173e-01,
  -3.368898534e-01, -3.311063058e-01, -3.253102922e-01, -3.195020308e-01,
  -3.136817404e-01, -3.078496400e-01, -3.020059493e-01, -2.961508882e-01,
  -2.902846773e-01, -2.844075372e-01, -2.785196894e-01, -2.726213554e-01,
  -2.667127575e-01, -2.607941179e-01, -2.548656596e-01, -2.489276057e-01,
  -2.429801799e-01, -2.370236060e-01, -2.310581083e-01, -2.250839114e-01,
  -2.191012402e-01, -2.131103199e-01, -2.071113762e-01, -2.011046348e-01,
  -1.950903220e-01, -1.890686641e-01, -1.830398880e-01, -1.770042204e-01,
  -1.709618888e-01, -1.649131205e-01, -1.588581433e-01, -1.527971853e-01,
  -1.467304745e-01, -1.406582393e-01, -1.345807085e-01, -1.284981108e-01,
  -1.224106752e-01, -1.163186309e-01, -1.102222073e-01, -1.041216339e-01,
  -9.801714033e-02, -9.190895650e-02, -8.579731234e-02, -7.968243797e-02,
  -7.356456360e-02, -6.744391956e-02, -6.132073630e-02, -5.519524435e-02,
  -4.906767433e-02, -4.293825693e-02, -3.680722294e-02, -3.067480318e-02,
  -2.454122852e-02, -1.840672991e-02, -1.227153829e-02, -6.135884649e-03,
  -2.449293598e-16,  6.135884649e-03,  1.227153829e-02,  1.840672991e-02,
   2.454122852e-02,  3.067480318e-02,  3.680722294e-02,  4.293825693e-02,
   4.906767433e-02,  5.519524435e-02,  6.132073630e-02,  6.744391956e-02,
   7.356456360e-02,  7.968243797e-02,  8.579731234e-02,  9.190895650e-02,
   9.801714033e-02,  1.041216339e-01,  1.102222073e-01,  1.163186309e-01,
   1.224106752e-01,  1.284981108e-01,  1.345807085e-01,  1.406582393e-01,
   1.467304745e-01,  1.527971853e-01,  1.588581433e-01,  1.649131205e-01,
   1.709618888e-01,  1.770042204e-01,  1.830398880e-01,  1.890686641e-01,
   1.950903220e-01,  2.011046348e-01,  2.071113762e-01,  2.131103199e-01,
   2.191012402e-01,  2.250839114e-01,  2.310581083e-01,  2.370236060e-01,
   2.429801799e-01,  2.489276057e-01,  2.548656596e-01,  2.607941179e-01,
   2.667127575e-01,  2.726213554e-01,  2.785196894e-01,  2.844075372e-01,
   2.902846773e-01,  2.961508882e-01,  3.020059493e-01,  3.078496400e-01,
   3.136817404e-01,  3.195020308e-01,  3.253102922e-01,  3.311063058e-01,
   3.368898534e-01,  3.426607173e-01,  3.484186802e-01,  3.541635254e-01,
   3.598950365e-01,  3.656129978e-01,  3.713171940e-01,  3.770074102e-01,
   3.826834324e-01,  3.883450467e-01,  3.939920401e-01,  3.996241998e-01,
   4.052413140e-01,  4.108431711e-01,  4.164295601e-01,  4.220002708e-01,
   4.275550934e-01,  4.330938189e-01,  4.386162385e-01,  4.441221446e-01,
   4.496113297e-01,  4.550835871e-01,  4.605387110e-01,  4.659764958e-01,
   4.713967368e-01,  4.767992301e-01,  4.821837721e-01,  4.875501601e-01,
   4.928981922e-01,  4.982276670e-01,  5.035383837e-01,  5.088301425e-01,
   5.141027442e-01,  5.193559902e-01,  5.245896827e-01,  5.298036247e-01,
   5.349976199e-01,  5.401714727e-01,  5.453249884e-01,  5.504579729e-01,
   5.555702330e-01,  5.606615762e-01,  5.657318108e-01,  5.707807459e-01,
   5.758081914e-01,  5.808139581e-01,  5.857978575e-01,  5.907597019e-01,
   5.956993045e-01,  6.006164794e-01,  6.055110414e-01,  6.103828063e-01,
   6.152315906e-01,  6.200572118e-01,  6.248594881e-01,  6.296382389e-01,
   6.343932842e-01,  6.391244449e-01,  6.438315429e-01,  6.485144010e-01,
   6.531728430e-01,  6.578066933e-01,  6.624157776e-01,  6.669999223e-01,
   6.715589548e-01,  6.760927036e-01,  6.806009978e-01,  6.850836678e-01,
   6.895405447e-01,  6.939714609e-01,  6.983762494e-01,  7.027547445e-01,
   7.071067812e-01,  7.114321957e-01,  7.157308253e-01,  7.200025080e-01,
   7.242470830e-01,  7.284643904e-01,  7.326542717e-01,  7.368165689e-01,
   7.409511254e-01,  7.450577854e-01,  7.491363945e-01,  7.531867990e-01,
   7.572088465e-01,  7.612023855e-01,  7.651672656e-01,  7.691033376e-01,
   7.730104534e-01,  7.768884657e-01,  7.807372286e-01,  7.845565972e-01,
   7.883464276e-01,  7.921065773e-01,  7.958369046e-01,  7.995372691e-01,
   8.032075315e-01,  8.068475535e-01,  8.104571983e-01,  8.140363297e-01,
   8.175848132e-01,  8.211025150e-01,  8.245893028e-01,  8.280450453e-01,
   8.314696123e-01,  8.348628750e-01,  8.382247056e-01,  8.415549774e-01,
   8.448535652e-01,  8.481203448e-01,  8.513551931e-01,  8.545579884e-01,
   8.577286100e-01,  8.608669386e-01,  8.639728561e-01,  8.670462455e-01,
   8.700869911e-01,  8.730949784e-01,  8.760700942e-01,  8.790122264e-01,
   8.819212643e-01,  8.847970984e-01,  8.876396204e-01,  8.904487232e-01,
   8.932243012e-01,  8.959662498e-01,  8.986744657e-01,  9.013488470e-01,
   9.039892931e-01,  9.065957045e-01,  9.091679831e-01,  9.117060320e-01,
   9.142097557e-01,  9.166790599e-01,  9.191138517e-01,  9.215140393e-01,
   9.238795325e-01,  9.262102421e-01,  9.285060805e-01,  9.307669611e-01,
   9.329927988e-01,  9.351835099e-01,  9.373390119e-01,  9.394592236e-01,
   9.415440652e-01,  9.435934582e-01,  9.456073254e-01,  9.475855910e-01,
   9.495281806e-01,  9.514350210e-01,  9.533060404e-01,  9.551411683e-01,
   9.569403357e-01,  9.587034749e-01,  9.604305194e-01,  9.621214043e-01,
   9.637760658e-01,  9.653944417e-01,  9.669764710e-01,  9.685220943e-01,
   9.700312532e-01,  9.715038910e-01,  9.729399522e-01,  9.743393828e-01,
   9.757021300e-01,  9.770281427e-01,  9.783173707e-01,  9.795697657e-01,
   9.807852804e-01,  9.819638691e-01,  9.831054874e-01,  9.842100924e-01,
   9.852776424e-01,  9.863080972e-01,  9.873014182e-01,  9.882575677e-01,
   9.891765100e-01,  9.900582103e-01,  9.909026354e-01,  9.917097537e-01,
   9.924795346e-01,  9.932119492e-01,  9.939069700e-01,  9.945645707e-01,
   9.951847267e-01,  9.957674145e-01,  9.963126122e-01,  9.968202993e-01,
   9.972904567e-01,  9.977230666e-01,  9.981181129e-01,  9.984755806e-01,
   9.987954562e-01,  9.990777278e-01,  9.993223846e-01,  9.995294175e-01,
   9.996988187e-01,  9.998305818e-01,  9.999247018e-01,  9.999811753e-01,
   1.000000000e+00,
};