#define MAKE_INTEGRAL_FRACTIONAL(x) int32_t x ## _integral = static_cast<int32_t>(x); float x ## _fractional = x - static_cast<float>(x ## _integral);

float interpolate(const float* table, float index, float size) {
  index *= size;
  MAKE_INTEGRAL_FRACTIONAL(index)
  float a = table[index_integral];
  float b = table[index_integral + 1];
  return a + (b - a) * index_fractional;
}

float fmap(int x, float in_min, float in_max, float out_min, float out_max){
    return ((float)x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float polyblep(float dt, float t){
  if (t < dt) {
        t /= dt;
        return  t+t - t*t - 1.0;
    }
    else if (t > 1.0 - dt) {
        t = (t - 1.0) / dt;
        return t*t + t+t + 1.0;
    }
    return 0.0;
}