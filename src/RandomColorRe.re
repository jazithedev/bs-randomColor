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
  | FormatHsl
  | FormatHsla
  | FormatHex;

let formatToString =
  fun
  | FormatRgb => "rgb"
  | FormatRgba => "rgba"
  | FormatHsl => "hsl"
  | FormatHsla => "hsla"
  | FormatHex => "hex";

type formatArray =
  | FormatRgbArray
  | FormatHslArray;

let formatArrayToString =
  fun
  | FormatRgbArray => "rgbArray"
  | FormatHslArray => "hslArray";

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
    (~luminosity=LuminosityBright, ~format=FormatHex, ~hue=?, ~hueHex=?, ~seed=?, ~alpha=?, ()) =>
  ()
  |> config(
       ~luminosity=?Belt.Option.map(Some(luminosity), luminosityToString),
       ~format=?Belt.Option.map(Some(format), formatToString),
       ~hue=?Belt.Option.map(hue, hueToString),
       ~hueHex?,
       ~seed?,
       ~alpha?,
     )
  |> randomColor;

/**
 * Version of randomColor which will return multiple color values.
 */

type configForMultiple;

[@bs.obj]
external configForMultiple:
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
  configForMultiple =
  "";

[@bs.module] external randomColorMultiple: configForMultiple => array(string) = "randomcolor";

let randomColorMultiple =
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
  |> configForMultiple(
       ~luminosity=?Belt.Option.map(Some(luminosity), luminosityToString),
       ~format=?Belt.Option.map(Some(format), formatToString),
       ~hue=?Belt.Option.map(hue, hueToString),
       ~hueHex?,
       ~seed?,
       ~count?,
       ~alpha?,
     )
  |> randomColorMultiple;

/**
 * Version of randomColor which will return RGB format as an array.
 */

type configForRgbArray;

[@bs.obj]
external configForRgbArray:
  (
    ~luminosity: string=?,
    ~format: string=?,
    ~seed: string=?,
    ~hue: string=?,
    ~hueHex: string=?,
    unit
  ) =>
  configForRgbArray =
  "";

[@bs.module] external randomColorRgbArray: configForRgbArray => (int, int, int) = "randomcolor";

let randomColorRgbArray = (~luminosity=LuminosityBright, ~seed=?, ~hue=?, ~hueHex=?, ()) =>
  ()
  |> configForRgbArray(
       ~luminosity=?Belt.Option.map(Some(luminosity), luminosityToString),
       ~format=formatArrayToString(FormatRgbArray),
       ~hue=?Belt.Option.map(hue, hueToString),
       ~hueHex?,
       ~seed?,
     )
  |> randomColorRgbArray;

/**
 * Version of randomColor which will return HSL format as an array.
 */

type configForHslArray;

[@bs.obj]
external configForHslArray:
  (
    ~luminosity: string=?,
    ~format: string=?,
    ~seed: string=?,
    ~hue: string=?,
    ~hueHex: string=?,
    unit
  ) =>
  configForHslArray =
  "";

[@bs.module]
external randomColorHslArray: configForHslArray => (int, float, float) = "randomcolor";

let randomColorHslArray = (~luminosity=LuminosityBright, ~seed=?, ~hue=?, ~hueHex=?, ()) =>
  ()
  |> configForHslArray(
       ~luminosity=?Belt.Option.map(Some(luminosity), luminosityToString),
       ~format=formatArrayToString(FormatHslArray),
       ~hue=?Belt.Option.map(hue, hueToString),
       ~hueHex?,
       ~seed?,
     )
  |> randomColorHslArray;
