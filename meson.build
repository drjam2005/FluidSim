project(
  'FluidSim',
  'cpp',
  version : '0.1',
  meson_version : '>= 1.3.0',
  default_options : ['warning_level=3', 'cpp_std=c++14'],
)

raylib_dep = declare_dependency(
  include_directories: include_directories('include'),
  link_args: ['-L' + meson.project_source_root() / 'lib', '-lraylib'],
)

dependencies = [
  raylib_dep
]

includeDirs = include_directories('include')

src = [
  'src/main.cpp',
  'src/particle.cpp',
  'src/system.cpp',
]

exe = executable(
  'FluidSim',
  src,
  install : true,
  include_directories : includeDirs,
  dependencies : dependencies,
)

test('basic', exe)
