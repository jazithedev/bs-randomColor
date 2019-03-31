# bs-randomColor
[BuckleScript](https://github.com/bloomberg/bucklescript)
bindings for [davidmerfield/randomColor](https://github.com/davidmerfield/randomColor/)
(library for generating attractive random colors). This implementation gives
couple functions:
- `randomColor()`<br />
Generate single color.
- `randomColorMultiple()`<br />
Generate multiple colors.
- `randomColorHslArray()`<br />
Generate single color with tuple as an output (`(int, int, int)`).
- `randomColorRgbArray()`<br />
Generate single color with tuple as an output (`(int, float, float)`).

## How to install

```
yarn add bs-randomcolor
```

Then add `bs-randomcolor` as a dependency to `bsconfig.json`:

```diff
"bs-dependencies": [
+  "bs-randomcolor"
]
```

## Supported options

- **hue**<br />
Controls the hue of the generated color. Possible values:
  - `HueRed`
  - `HueOrange`
  - `HueYellow`
  - `HueGreen`
  - `HueBlue`
  - `HuePurple`
  - `HuePink`
  - `HueMonochrome`
- **hueHex**<br />
Hexadecimal value of any color which will be used instead of "hue" option. The randomColor will extract its hue value and use that to generate colors.

- **luminosity**<br />
Controls the luminosity of the generated color. Possible values:
  - `LuminosityBright` (default)
  - `LuminosityLight`
  - `LuminosityDark`

- **count**<br />
An integer which specifies the number of colors to generate.<br />
**Notice:** option available only for `randomColorMultiple()`.

- **seed**<br />
An integer or string which when passed will cause randomColor to return the same color each time.

- **format**<br />
Specifies the format of the generated color. Possible values:
  - `FormatHex` (default)
  - `FormatRgb`
  - `FormatRgba`
  - `FormatHsl`
  - `FormatHsla`
  - `FormatRgbArray` (available only for `randomColorRgbArray()`)
  - `FormatHslArray` (available only for `randomColorHslArray()`)

- **alpha**<br />A decimal between 0 and 1. Only relevant when using a format with an alpha channel (`FormatRgba` and `FormatHsla`). Defaults to a random value.

## Example usages:

```reason
open RandomColorRe;

randomColor(); // "#f9a05c"
randomColor(~seed="test", ~format=FormatRgb, ()); // "rgb(249, 160, 92)"
randomColor(~seed="test", ~format=FormatRgba, ~alpha=0.2, ()) // "rgba(249, 160, 92, 0.2)"
randomColor(~seed="test", ~hue=HuePurple, ~luminosity=LuminosityDark, ()) // "#070707"
randomColorMultiple(~seed="test123", ~count=3, ()) // [|"#b6f453", "#4cdbb2", "#f9d759"|]
randomColorMultiple(~seed="test123", ~count=3, ()) // [|"#b6f453", "#4cdbb2", "#f9d759"|]
randomColorRgbArray(~seed="test", ~hue=HueRed, ()) // (137, 4, 44)
randomColorHslArray(~seed="test", ()) // (71, 94.17, 23.69)
```

More examples in tests :).