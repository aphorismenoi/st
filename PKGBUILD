# Contributor: Patrick Jackson <PatrickSJackson gmail com>
# Maintainer: Christoph Vigano <mail@cvigano.de>

pkgname=st
pkgver=0.8.2
pkgrel=2
pkgdesc='A simple virtual terminal emulator for X.'
arch=('i686' 'x86_64')
license=('MIT')
depends=('libxft' 'libxext' 'xorg-fonts-misc')
makedepends=('ncurses')
url="http://st.suckless.org"
source=(http://dl.suckless.org/st/$pkgname-$pkgver.tar.gz
        config.h)

_patches=(01-hidecursor.diff
          02-scrollback.diff
          03-clipboard.diff
          04-disable_bold_italic_fonts.diff
          05-copyurl.diff 
          )

source=(${source[@]} ${_patches[@]})

prepare() {
  cd $srcdir/$pkgname-$pkgver
  # skip terminfo which conflicts with nsurses
  sed -i '/tic /d' Makefile
  cp $srcdir/config.h config.h
}

build() {
  cd $srcdir/$pkgname-$pkgver

  echo "==> Applying Patches"
  for p in "${_patches[@]}"; do
    echo "  -> $p"
    patch < ../$p || return 1
  done

  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make PREFIX=/usr DESTDIR="$pkgdir" TERMINFO="$pkgdir/usr/share/terminfo" install
  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -Dm644 README "$pkgdir/usr/share/doc/$pkgname/README"
}

md5sums=('a3d97ee92215071e6399691edc0f04b0'
         '6af27690583a8ad11ee328fde7e58ee1'
         '7b6f4a1efe7987b8f5554b4ec16082f9'
         '599ecd7c6f7b4cf8d1e54f909aaa071b'
         'd7295edae3ff61b93e9f875f6eaaad7a'
         '6dd144a1ba5e3b953cb17fe28fc0fa44'
         '8908051f05e965e9880a484d1618e4d5')
