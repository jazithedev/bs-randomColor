[@bs.deriving jsConverter]
type luminosity = [ | `bright | `light | `dark];

[@bs.deriving jsConverter]
type format = [ | `rgb | `rgba | `rgbArray | `hsl | `hsla | `hslArray | `hex];

[@bs.deriving jsConverter]
type hue = [ | `red | `orange | `yellow | `green | `blue | `purple | `pink | `monochrome];

[@bs.deriving abstract]
type randomColorOptions = {
  [@bs.optional]
  seed: option(string),
  [@bs.optional]
  count: option(int),
  [@bs.optional]
  alpha: option(float),
  [@bs.optional]
  hue: string,
  [@bs.optional]
  format: string,
  [@bs.optional]
  luminosity: string,
};

[@bs.module] external randomColorExternal: randomColorOptions => string = "randomcolor";

let randomColor = (~luminosity=?, ~format=?, ~hue=?, ~hueCustom=?, ~seed=?, ~count=?, ~alpha=?, ()) => {
  let luminosityVal =
    switch (hueCustom, luminosity) {
    | (Some(value), _) => value
    | (None, Some(value)) => luminosityToJs(value)
    | (None, None) => "bright"
    };

  let formatVal =
    switch (format) {
    | Some(value) => formatToJs(value)
    | None => "hex"
    };

  let hueVal =
    switch (hue) {
    | Some(value) => hueToJs(value)
    | None => "hex"
    };

  let isAlphaValid = (alpha: option(float)) => {
    switch (alpha) {
    | None => true
    | Some(value) => value >= 0.0 && value <= 1.0
    };
  };

  if (isAlphaValid(alpha) === false) {
    Js.Console.error("Alpha value is not valid (should be float between 0 and 1).");
  };

  let colorOpts =
    randomColorOptions(~seed, ~count, ~alpha, ~luminosity=luminosityVal, ~format=formatVal, ~hue=hueVal, ());

  randomColorExternal(colorOpts);
};
