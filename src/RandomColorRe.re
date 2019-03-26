type hue =
  | HueRed
  | HueOrange
  | HueYellow
  | HueGreen
  | HueBlue
  | HuePurple
  | HuePink
  | HueMonochrome;

let hueToString =
  fun
  | HueRed => "red"
  | HueOrange => "orange"
  | HueYellow => "yellow"
  | HueGreen => "green"
  | HueBlue => "blue"
  | HuePurple => "purple"
  | HuePink => "pink"
  | HueMonochrome => "monochrome";

type format =
  | FormatRgb
  | FormatRgba
  | FormatRgbArray
  | FormatHsl
  | FormatHsla
  | FormatHslArray
  | FormatHex;

let formatToString =
  fun
  | FormatRgb => "rgb"
  | FormatRgba => "rgba"
  | FormatRgbArray => "rgbArray"
  | FormatHsl => "hsl"
  | FormatHsla => "hsla"
  | FormatHslArray => "hslArray"
  | FormatHex => "hex";

type luminosity =
  | LuminosityBright
  | LuminosityLight
  | LuminosityDark;

let luminosityToString =
  fun
  | LuminosityBright => "bright"
  | LuminosityLight => "light"
  | LuminosityDark => "dark";

type config;

[@bs.obj]
external config:
  (
    ~seed: string=?,
    ~hueHex: string=?,
    ~count: int=?,
    ~alpha: float=?,
    ~hue: string=?,
    ~format: string=?,
    ~luminosity: string=?,
    unit
  ) =>
  config =
  "";

[@bs.module] external randomColor: config => string = "randomcolor";

let randomColor =
    (
      ~luminosity=LuminosityBright,
      ~format=FormatHex,
      ~hue=?,
      ~hueHex=?,
      ~seed=?,
      ~count=?,
      ~alpha=?,
      (),
    ) =>
  ()
  |> config(
       ~luminosity=?Belt.Option.map(Some(luminosity), luminosityToString),
       ~format=?Belt.Option.map(Some(format), formatToString),
       ~hue=?Belt.Option.map(hue, hueToString),
       ~hueHex?,
       ~seed?,
       ~count?,
       ~alpha?,
     )
  |> randomColor;
