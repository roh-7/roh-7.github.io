$(document).ready(function() {
  var idleMouseTimer;
  var forceMouseHide = false;

  // $("body").css('cursor', 'none');

  $("#areaToHideCursor").hover(function(e) {
    $("body").css('cursor', 'none');
  });

  $("#areaToHideCursor").mouseleave(function(e) {
    $("body").css('cursor', '');
  });
});
