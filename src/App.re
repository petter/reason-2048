type board_t = array(array(int));

type state = {board: board_t};

type actions =
  | UpdateBoard(board_t);

let initialBoard = Array.make_matrix(4, 4, 0);
initialBoard[Random.int(4)][Random.int(4)] = 2;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | UpdateBoard(newBoard) => {...state, board: newBoard}
        },
      {board: initialBoard},
    );

  let rowStyle = ReactDOMRe.Style.make(~display="flex", ~flexFlow="row", ());
  let rowExtraStyle =
    ReactDOMRe.Style.make(~marginBottom=Constants.margin, ());

  let board =
    Array.mapi(
      (y, row) =>
        <div
          key={string_of_int(y)}
          className="row"
          style={
            y === 3
              ? rowStyle : ReactDOMRe.Style.combine(rowStyle, rowExtraStyle)
          }>
          {Array.mapi(
             (x, cell) =>
               <Cell
                 last={x === 3}
                 key={String.concat(
                   ", ",
                   [string_of_int(x), string_of_int(y)],
                 )}>
                 cell
               </Cell>,
             row,
           )
           ->ReasonReact.array}
        </div>,
      state.board,
    );

  <div
    style={ReactDOMRe.Style.make(
      ~display="flex",
      ~justifyContent="center",
      (),
    )}>
    <div
      style={ReactDOMRe.Style.make(
        ~display="flex",
        ~flexFlow="column",
        ~backgroundColor="#bbada0",
        ~padding="1.75vw",
        ~borderRadius=Constants.borderRadius,
        ~height="85.25vw",
        ~width="85.25vw",
        (),
      )}>
      {ReasonReact.array(board)}
    </div>
  </div>;
};