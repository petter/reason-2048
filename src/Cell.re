[@bs.val] external log2: float => float = "Math.log2";

[@react.component]
let make = (~children, ~last) => {
  let tileColors = [|
    "rgba(238, 228, 218, 0.35)",
    "#eee4da",
    "#ede0c8",
    "#f2b179",
  |];

  let cellStyle =
    ReactDOMRe.Style.make(
      ~width="20vw",
      ~height="20vw",
      ~display="flex",
      ~justifyContent="center",
      ~alignItems="center",
      ~fontSize="10vw",
      ~color="#776e65",
      ~fontFamily="'Clear Sans', 'Helvetica Neue', Arial, sans-serif",
      ~fontWeight="bold",
      ~backgroundColor=tileColors[log2(float_of_int(children))->int_of_float],
      ~borderRadius=Constants.borderRadius,
      (),
    );

  let cellExtraStyle =
    ReactDOMRe.Style.make(~marginRight=Constants.margin, ());

  <div
    style={
      last ? cellStyle : ReactDOMRe.Style.combine(cellStyle, cellExtraStyle)
    }>
    {switch (children) {
     | 0 => ReasonReact.null
     | _ => string_of_int(children)->ReasonReact.string
     }}
  </div>;
};