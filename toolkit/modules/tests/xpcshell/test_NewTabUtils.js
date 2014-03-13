/* Any copyright is dedicated to the Public Domain.
   http://creativecommons.org/publicdomain/zero/1.0/ */

// See also browser/base/content/test/newtab/.

const { classes: Cc, interfaces: Ci, results: Cr, utils: Cu } = Components;
Cu.import("resource://gre/modules/NewTabUtils.jsm");

function run_test() {
  for (test of tests) {
    test();
  }
}

let tests = [

  function multipleProviders() {
    // Make each provider generate NewTabUtils.links.maxNumLinks links to check
    // that no more than maxNumLinks are actually returned in the merged list.
    let evenFrecencyProvider = new TestProvider(function (done) {
      let links = [];
      for (let i = NewTabUtils.links.maxNumLinks * 2 - 2; i >= 0; i -= 2) {
        links.push({
          url: "http://example.com/" + i,
          frecency: i,
          lastVisitDate: 0,
        });
      }
      done(links);
    });
    let oddFrecencyProvider = new TestProvider(function (done) {
      let links = [];
      for (let i = NewTabUtils.links.maxNumLinks * 2 - 1; i >= 1; i -= 2) {
        links.push({
          url: "http://example.com/" + i,
          frecency: i,
          lastVisitDate: 0,
        });
      }
      done(links);
    });

    NewTabUtils.initWithoutProviders();
    NewTabUtils.links.addProvider(evenFrecencyProvider);
    NewTabUtils.links.addProvider(oddFrecencyProvider);

    // This is sync since the providers' getLinks are sync.
    NewTabUtils.links.populateCache(function () {}, false);

    let links = NewTabUtils.links.getLinks();
    do_check_true(Array.isArray(links));
    do_check_eq(links.length, NewTabUtils.links.maxNumLinks);
    for (let i = 0; i < NewTabUtils.links.maxNumLinks; i++) {
      let link = links[i];
      let frecency = NewTabUtils.links.maxNumLinks * 2 - i - 1;
      do_check_eq(link.url, "http://example.com/" + frecency);
      do_check_eq(link.frecency, frecency);
    }

    NewTabUtils.links.removeProvider(evenFrecencyProvider);
    NewTabUtils.links.removeProvider(oddFrecencyProvider);
  },
];

function TestProvider(getLinksFn) {
  this.getLinks = getLinksFn;
}

TestProvider.prototype = {
  addObserver: function (observer) {},
};
