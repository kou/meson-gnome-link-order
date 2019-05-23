#!/usr/bin/env python3

import gi
gi.require_version('Meson', '1.0')

from gi.repository import Meson

sample = Meson.SampleAfter()
sample.print_message('Hello')
