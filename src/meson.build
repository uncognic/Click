click_sources = [
  'main.c',
  'click-application.c',
  'click-window.c',
]

click_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.4'),
]

click_sources += gnome.compile_resources('click-resources',
  'click.gresource.xml',
  c_name: 'click'
)

executable('click', click_sources,
  dependencies: click_deps,
       install: true,
)
