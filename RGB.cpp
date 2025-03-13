#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class CMYK;
class HSV;

class Color {
public:
    virtual void print() const = 0;
};

class RGB : public Color {
public:
    int red, green, blue;

    RGB(int r = 0, int g = 0, int b = 0) {
        this->red = r;
        this->green = g;
        this->blue = b;

    }

    void print() const override {
        std::cout << "RGB: (" << red << ", " << green << ", " << blue << ")\n";
    }

    CMYK toCMYK() const;
    HSV toHSV() const;

    RGB mix(const RGB& other) const {
        return RGB((red + other.red) / 2, (green + other.green) / 2, (blue + other.blue) / 2);
    }
};

class CMYK : public Color {
public:
    double cyan, magenta, yellow, black;

    CMYK(double c = 0, double m = 0, double y = 0, double k = 0) {
        this->cyan = c;
        this->magenta = m;
        this->yellow = y;
        this->black = k;
    }

    void print() const override {
        cout << "CMYK: (" << cyan << ", " << magenta << ", " << yellow << ", " << black << ")\n";
    }

    RGB toRGB() const;
    HSV toHSV() const;

    CMYK mix(const CMYK& other) const {
        return CMYK((cyan + other.cyan) / 2, (magenta + other.magenta) / 2, (yellow + other.yellow) / 2, (black + other.black) / 2);
    }
};

class HSV : public Color {
public:
    double hue, saturation, value;

    HSV(double h = 0, double s = 0, double v = 0) {
        this->hue = h;
        this->saturation = s;
        this->value = v;
    }

    void print() const override {
        cout << "HSV: (" << hue << ", " << saturation << ", " << value << ")\n";
    }

    RGB toRGB() const;
    CMYK toCMYK() const;

    HSV mix(const HSV& other) const {
        return HSV((hue + other.hue) / 2, (saturation + other.saturation) / 2, (value + other.value) / 2);
    }
};

CMYK RGB::toCMYK() const {
    double r = red / 255.0;
    double g = green / 255.0;
    double b = blue / 255.0;

    double k = 1 - std::max(std::max(r, g), b);
    double c = (1 - r - k) / (1 - k);
    double m = (1 - g - k) / (1 - k);
    double y = (1 - b - k) / (1 - k);

    return CMYK(c, m, y, k);
}

HSV RGB::toHSV() const {
    double r = red / 255.0;
    double g = green / 255.0;
    double b = blue / 255.0;

    double max = std::max(std::max(r, g), b);
    double min = std::min(std::min(r, g), b);
    double delta = max - min;

    double h = 0, s = 0, v = max;

    if (delta != 0) {
        s = delta / max;

        if (max == r) {
            h = 60 * (((g - b) / delta));
            if (h < 0) h += 360;
        }
        else if (max == g) {
            h = 60 * (((b - r) / delta) + 2);
        }
        else if (max == b) {
            h = 60 * (((r - g) / delta) + 4);
        }
    }

    return HSV(h, s, v);
}

RGB CMYK::toRGB() const {
    double r = 255 * (1 - cyan) * (1 - black);
    double g = 255 * (1 - magenta) * (1 - black);
    double b = 255 * (1 - yellow) * (1 - black);

    int red = (r >= 0) ? (int)(r + 0.5) : (int)(r - 0.5);
    int green = (g >= 0) ? (int)(g + 0.5) : (int)(g - 0.5);
    int blue = (b >= 0) ? (int)(b + 0.5) : (int)(b - 0.5);

    return RGB(red, green, blue);
}

HSV CMYK::toHSV() const {
    RGB rgb = this->toRGB();
    return rgb.toHSV();
}

RGB HSV::toRGB() const {
    double c = value * saturation;
    double x = c * (1 - std::fabs((hue / 60) - 1));
    double m = value - c;

    double r = 0, g = 0, b = 0;

    if (hue >= 0 && hue < 60) {
        r = c; g = x; b = 0;
    }
    else if (hue >= 60 && hue < 120) {
        r = x; g = c; b = 0;
    }
    else if (hue >= 120 && hue < 180) {
        r = 0; g = c; b = x;
    }
    else if (hue >= 180 && hue < 240) {
        r = 0; g = x; b = c;
    }
    else if (hue >= 240 && hue < 300) {
        r = x; g = 0; b = c;
    }
    else if (hue >= 300 && hue < 360) {
        r = c; g = 0; b = x;
    }

    r = (r + m) * 255;
    g = (g + m) * 255;
    b = (b + m) * 255;

    int red = (r >= 0) ? (int)(r + 0.5) : (int)(r - 0.5);
    int green = (g >= 0) ? (int)(g + 0.5) : (int)(g - 0.5);
    int blue = (b >= 0) ? (int)(b + 0.5) : (int)(b - 0.5);

    return RGB(red, green, blue);
}

CMYK HSV::toCMYK() const {
    RGB rgb = this->toRGB();
    return rgb.toCMYK();
}

int main() {
    RGB rgb1(255, 0, 0); 
    RGB rgb2(0, 0, 255); 

    RGB mixedRGB = rgb1.mix(rgb2);
    mixedRGB.print();

    CMYK cmyk = mixedRGB.toCMYK();
    cmyk.print();

    HSV hsv = mixedRGB.toHSV();
    hsv.print();

    return 0;
}
