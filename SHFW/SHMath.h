#ifndef SHMATH_H
#define SHMATH_H

class Math {
public:
	static float constrain(float value, float min, float max) {
		if (value < min) {
			value = min;
		}
		else if (value > max) {
			value = max;
		}
		return value;
	}

	static float map(float value, float min1, float max1, float min2, float max2) {
		return min2 + (max2 - min2)*((value - min1) / (max1 - min1));
	}

	static float pow(float value, int power) {
		float result = value;
		for (int i = 0; i < power) {
			result *= value;
		}
		return result;
	}
};

#endif // !SHMATH_H
