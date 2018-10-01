# Contributor: Patrick Jackson <PatrickSJackson gmail com>
# Maintainer: Christoph Vigano <mail@cvigano.de>

pkgname=st
pkgver=0.8.1
pkgrel=1
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
sha256sums=('c4fb0fe2b8d2d3bd5e72763e80a8ae05b7d44dbac8f8e3bb18ef0161c7266926'
            '24057e7d944e06540deb2b799e25294f148da9ec77e983a42da5b43abca31ec2'
            'bf3fe4e855f67fc9ae69b7328399ce06567f6aae3c9fb7fc8e7ec26c89e41dfd'
            '8279d347c70bc9b36f450ba15e1fd9ff62eedf49ce9258c35d7f1cfe38cca226'
            'f22e0165aacb2bc86d000728c81f68022abcc601dbfd09e516e1ba772225d7e6'
            '6e583be1835b15b2d1be346752ab4416b3069376dd42b97e155612419ad7e22e'
            '6ebde522b18594c2290d44de6a99fafef376240d0478e6e44b36e1114b9fe9a8')
