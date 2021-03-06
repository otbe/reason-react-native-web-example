external browserRouter : ReactRe.reactClass = "BrowserRouter" [@@bs.module "react-router-dom"];

external _switch : ReactRe.reactClass = "Switch" [@@bs.module "react-router-dom"];

external navLink : ReactRe.reactClass = "NavLink" [@@bs.module "react-router-dom"];

external route : ReactRe.reactClass = "Route" [@@bs.module "react-router-dom"];

type rrfn = Js.t {. _match : Js.t {. url : string}};

module Route = {
  let createElement exact::(exact: bool) path::(path: string) component::(component: 'a) =>
    ReactRe.wrapPropsShamelessly
      route {"exact": Js.Boolean.to_js_boolean exact, "path": path, "component": component};
};

module NavLink = {
  let createElement
      _to::(_to: string)
      activeClassName::(activeClassName: option string)=?
      className::(className: option string)=? =>
    ReactRe.wrapPropsShamelessly
      navLink
      {
        "activeClassName": Js.Null_undefined.from_opt activeClassName,
        "className": Js.Null_undefined.from_opt className,
        "to": _to
      };
};

module BrowserRouter = {
  let createElement = ReactRe.wrapPropsShamelessly browserRouter (Js.Obj.empty ());
};


/**
 * The word `Switch` conflicts with React Native Web here. So we are going to import
 * RR4's <Switch /> as <RRSwitch />
 */
module RRSwitch = {
  let createElement = ReactRe.wrapPropsShamelessly _switch (Js.Obj.empty ());
};
