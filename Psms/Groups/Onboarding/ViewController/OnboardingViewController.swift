import UIKit

class OnboardingViewController: UIViewController {
    
    @IBOutlet weak var skipButton: UIButton!
    @IBOutlet var contentView: UIView!
    @IBOutlet var scrollView: UIScrollView!
    @IBOutlet var pageControl: UIPageControl!
    
    var page = 1 {
        didSet {
            if page == slides.count - 1 {
                skipButton.setTitle("Finish".localized, for: .normal)
            }
            else {
                skipButton.setTitle("Next".localized, for: .normal)
            }
        }
    }
    let slides = OnboardingSliderEnum.allCases
    var frame = CGRect(x: 0, y: 0, width: 0, height: 0)
    override func viewDidLoad() {
        super.viewDidLoad()
        
        scrollView.delegate = self
        scrollView.contentSize = CGSize(width: UIScreen.main.bounds.width * CGFloat(slides.count), height: scrollView.frame.size.height)
        setupImages()
        page = 0
    }
    
    @IBAction func changePage(_ sender: Any) {
        page = pageControl.currentPage
        var frame: CGRect = scrollView.frame
        frame.origin.x = frame.size.width * CGFloat(page)
        frame.origin.y = 0
        scrollView.scrollRectToVisible(frame, animated: true)
    }
    @IBAction func skip(_ sender: Any) {
        if page == slides.count - 1 {
            showNext()
        }
        else {
            page += 1
            pageControl.currentPage = page
            scrollView.contentOffset.x = scrollView.frame.width * CGFloat(page)
        }
    }
    
    private func showNext() {
        presentInFullScreen(UIStoryboard(storyboard: .securitySetup).instantiateInitialViewController()!, animated: true)
    }
    
    func setupImages() {
        pageControl.numberOfPages = slides.count
        for i in 0..<slides.count {
            let imageView: UIImageView = {
                let imgView = UIImageView(frame: frame)
                imgView.contentMode = .scaleAspectFit
                imgView.clipsToBounds = true
                imgView.translatesAutoresizingMaskIntoConstraints = false
                return imgView
            }()
            
            let label: UILabel = {
                let lbl = UILabel()
                lbl.text = slides[i].title
                lbl.font = UIFont(name: "comfortaa", size: 14)
                lbl.textAlignment = .center
                lbl.translatesAutoresizingMaskIntoConstraints = false
                lbl.numberOfLines = 0
                return lbl
            }()
            frame.origin.x = UIScreen.main.bounds.width * CGFloat(i)
            frame.size = scrollView.frame.size
            frame.size.width = UIScreen.main.bounds.width
            
            imageView.image = UIImage(named: slides[i].imageName)
            scrollView.insertSubview(imageView, at: 0)
            NSLayoutConstraint.activate([
                imageView.heightAnchor.constraint(equalTo: scrollView.heightAnchor, multiplier: 0.6, constant: 0),
                imageView.centerXAnchor.constraint(equalTo: scrollView.centerXAnchor, constant: UIScreen.main.bounds.width * CGFloat(i)),
                imageView.topAnchor.constraint(equalTo: scrollView.topAnchor, constant: 50),
            ])
            
            scrollView.insertSubview(label, at: 0)
            
            NSLayoutConstraint.activate([
                label.centerXAnchor.constraint(equalTo: imageView.centerXAnchor, constant: 0),
                label.topAnchor.constraint(equalTo: imageView.bottomAnchor, constant: 30),
                label.widthAnchor.constraint(equalTo: scrollView.widthAnchor, multiplier: 0.75, constant: 0),
            ])
        }
    }
}

extension OnboardingViewController: UIScrollViewDelegate {
    func scrollViewDidEndDecelerating(_ scrollView: UIScrollView) {
        page = Int(scrollView.contentOffset.x / scrollView.frame.size.width)
        pageControl.currentPage = page
    }
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        if scrollView.contentOffset.y != 0 {
            scrollView.contentOffset.y = 0
        }
        if scrollView.contentOffset.x < 0 {
            scrollView.contentOffset.x = 0
        }
        if scrollView.contentOffset.x > (UIScreen.main.bounds.width * CGFloat(slides.count)) {
            scrollView.contentOffset.x = UIScreen.main.bounds.width * CGFloat(slides.count)
        }
    }
}
