open ReactNative;

let styles =
  StyleSheet.create
    Style.(
      {
        "wrapper":
          style [
            flexDirection `column,
            backgroundColor "#3398FF",
            marginVertical 16.,
            marginHorizontal 32.,
            paddingVertical 64.
          ],
        "text": style [color "#fff", fontSize 17., fontWeight `_500, marginLeft 15.]
      }
    );

module About = {
  include ReactRe.Component;
  let name = "About";
  type props = unit;
  let render _ =>
    <View style=styles##wrapper>
      <Text style=styles##text value="React Native Web is Awesome" />
    </View>;
};

include ReactRe.CreateComponent About;

let createElement = wrapProps ();
