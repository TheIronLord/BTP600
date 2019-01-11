// javascript reference to our sketch
var pjs = undefined;
var bound = false;

// bind JS to the p5 sketch for two way communication
function bindJavaScript() {
  if(Processing) { pjs = Processing.getInstanceById("a3"); }
  if (pjs !== undefined && pjs.bindJavaScript !== undefined) {
    pjs.bindJavaScript(this);
    bound = true; }
  if(!bound) setTimeout(bindJavaScript, 250);
}

// schedule binding
bindJavaScript();

function changeBorder(elem) {

    pjs.setBorder(elem.checked);
}