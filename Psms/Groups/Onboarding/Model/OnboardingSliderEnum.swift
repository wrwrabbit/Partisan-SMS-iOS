import Foundation

enum OnboardingSliderEnum: String, CaseIterable {
    
    case slide1
    case slide2
    case slide3
    case slide4
    
    var title: String {
        switch self {
        case .slide1:
            return "Slide1".localized
        case .slide2:
            return "Slide2".localized
        case .slide3:
            return "Slide3".localized
        case .slide4:
            return "Slide4".localized
        }
    }
    
    var imageName: String {
        switch self {
        case .slide1:
            return "slide1"
        case .slide2:
            return "slide2"
        case .slide3:
            return "slide3"
        case .slide4:
            return "slide4"
        }
    }
    
}
