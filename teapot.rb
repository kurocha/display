# Teapot v3.0.0 configuration generated at 2019-02-24 12:58:05 +1300

required_version "3.0"

define_project "display" do |project|
	project.title = "Display"
end

# Build Targets

define_target 'display-library' do |target|
	target.depends 'Language/C++14'
	
	target.depends 'Library/Input', public: true
	
	target.provides 'Library/Display' do
		source_root = target.package.path + 'source'
		
		library_path = build static_library: 'Display', source_files: source_root.glob('Display/**/*.cpp')
		
		append linkflags library_path
		append header_search_paths source_root
	end
end

define_target 'display-test' do |target|
	target.depends 'Library/Display'
	target.depends 'Library/UnitTest'
	
	target.depends 'Language/C++14'
	
	target.provides 'Test/Display' do |arguments|
		test_root = target.package.path + 'test'
		
		run tests: 'Display', source_files: test_root.glob('Display/**/*.cpp'), arguments: arguments
	end
end

define_target 'display-executable' do |target|
	target.depends 'Library/Display'
	
	target.depends 'Language/C++14'
	
	target.provides 'Executable/Display' do
		source_root = target.package.path + 'source'
		
		build executable: 'Display', source_files: source_root.glob('Display.cpp')
	end
end

define_target 'display-run' do |target|
	target.depends 'Executable/Display'
	
	target.depends :executor
	
	target.provides 'Run/Display' do |*arguments|
		run executable: 'Display', arguments: arguments
	end
end

# Configurations

define_configuration 'development' do |configuration|
	configuration[:source] = "https://github.com/kurocha"
	configuration.import "display"
	
	# Provides all the build related infrastructure:
	configuration.require 'platforms'
	
	# Provides unit testing infrastructure and generators:
	configuration.require 'unit-test'
	
	# Provides some useful C++ generators:
	configuration.require 'generate-cpp-class'
	
	configuration.require "generate-project"
end

define_configuration "display" do |configuration|
	configuration.public!
	
	configuration.require 'input'
end
