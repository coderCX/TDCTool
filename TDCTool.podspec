Pod::Spec.new do |s|
    s.name         = 'TDCTool'
    s.version      = '1.0.0'
    s.summary      = 'An easy way to use normal function'
    s.homepage     = 'https://github.com/coderCX/TDCTool'
    s.license      = 'MIT'
    s.authors      = {'程曦' => '460018082@qq.com'}
    s.platform     = :ios, '7.0'
    s.source       = {:git => 'https://github.com/coderCX/TDCTool.git', :tag => s.version}
    s.source_files = 'TDCTool/**/*.{h,m}'
    s.resource     = 'TDCTool/*'
    s.requires_arc = true
end
