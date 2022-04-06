import Foundation

// MARK: -
// MARK: - timestamp

extension Date {

    var timestamp: Int {
        return Int(timeIntervalSince1970)
    }
    
    var calendar: Calendar {
        var calendar = Calendar(identifier: .gregorian)
        calendar.timeZone = TimeZone(secondsFromGMT: 0)!
        return calendar
    }
    
    var localDateFromUTC: Date {
        let delta = TimeInterval(TimeZone.current.secondsFromGMT(for: self) - TimeZone(abbreviation: "UTC")!.secondsFromGMT(for: self))
                 return addingTimeInterval(delta)
    }

}

// MARK: -
// MARK: - getTimeAgo

extension Date {

    func getTimeAgo() -> String {
        let time = timestamp
        let MSKTime = time
        let now = Date().timestamp
        let diff = now - MSKTime
        let date = Date(timeIntervalSince1970: Double(time))
        let dateFormatter = DateFormatter()
        dateFormatter.locale = NSLocale.current
        dateFormatter.dateFormat = "HH:mm"
        let strDate = dateFormatter.string(from: date)
        if diff < 60 {
            return "1 minute ago"
        }
        else if diff < 3600 {
            return String(Int(diff / 60)) + " minutes ago"
        }
        else if diff < 7200 {
            return "hour ago"
        }
        else if diff < 86400 {
            return String(Int(diff / 3600)) + " hours ago"
        }
        else if diff < 172800 {
            dateFormatter.dateFormat = "HH:mm"

            return "yesterday " + strDate
        }
        else {
            dateFormatter.dateFormat = "MMMM dd HH:mm"

            return dateFormatter.string(from: date)
        }
    }

    func getActivityTimeAgo() -> String {
        let time = timestamp
        let MSKTime = time
        let now = Date().timestamp
        let diff = now - MSKTime
        if diff < 60 {
            return "Just now"
        }
        else if diff < 3600 {
            return String(Int(diff / 60)) + " m ago"
        }
        else if diff < 7200 {
            return "hour ago"
        }
        else if diff < 86400 {
            return String(Int(diff / 3600)) + "h ago"
        }
        else if diff < 172800 {
            return "yesterday"
        }
        else {
            return String(Int(diff / 86400)) + "d ago"
        }
    }

}

// MARK: -
// MARK: - get start and end

extension Date {

    var startOfDay: Date {
        return calendar.startOfDay(for: self)
    }

    var startOfMonth: Date {
        let components = calendar.dateComponents([.year, .month], from: startOfDay)
        return calendar.date(from: components)!
    }

    var startOfWeek: Date {
        let sunday = calendar.date(from: calendar.dateComponents([.yearForWeekOfYear, .weekOfYear], from: self))
        return calendar.date(byAdding: .day, value: 1, to: sunday!)!
    }
    
    var startOfWeekSunday: Date {
        let sunday = calendar.date(from: calendar.dateComponents([.yearForWeekOfYear, .weekOfYear], from: self))
        return sunday!
    }

    var startOfYear: Date {
        let components = calendar.dateComponents([.year], from: startOfDay)
        return calendar.date(from: components)!
    }

    var endOfDay: Date {
        var components = DateComponents()
        components.day = 1
        components.second = -1
        return calendar.date(byAdding: components, to: startOfDay)!
    }

    var endOfMonth: Date {
        var components = DateComponents()
        components.month = 1
        components.second = -1
        return calendar.date(byAdding: components, to: startOfMonth)!
    }

    var endOfYear: Date {
        var components = DateComponents()
        components.year = 1
        components.second = -1
        return calendar.date(byAdding: components, to: startOfYear)!
    }

    func isMonday() -> Bool {
        let components = calendar.dateComponents([.weekday], from: self)
        return components.weekday == 2
    }

}

// MARK: -
// MARK: - from timestamp

extension Date {

    init(timestamp: Int) {
        self.init(timeIntervalSince1970: Double(timestamp))
    }

}

// MARK: -
// MARK: - yesterday + tomorrow

extension Date {

    static var yesterday: Date { return Date().dayBefore }
    static var tomorrow: Date { return Date().dayAfter }

    var dayBefore: Date {
        return calendar.date(byAdding: .day, value: -1, to: noon)!
    }

    var dayAfter: Date {
        return calendar.date(byAdding: .day, value: 1, to: noon)!
    }

    var noon: Date {
        return calendar.date(bySettingHour: 12, minute: 0, second: 0, of: self)!
    }

    var month: Int {
        return calendar.component(.month, from: self)
    }
    
    var day: Int {
        return calendar.component(.day, from: self)
    }
    
    var year: Int {
        return calendar.component(.year, from: self)
    }

    var isLastDayOfMonth: Bool {
        return dayAfter.month != month
    }

}

// MARK: -
// MARK: - string to date

extension Date {

    var mediumDate: String {
        let dateFormatter = DateFormatter()
        var template = "MM.dd.yyyy"
        if Calendar.current.component(.year, from: self) < 1910 {
            template = "MM.dd"
        }
        dateFormatter.dateFormat = DateFormatter.dateFormat(fromTemplate: template, options: 0, locale: Locale.current)
        return dateFormatter.string(from: self)
    }
    
    var mediumDateUTC: String {
        let dateFormatter = DateFormatter()
        dateFormatter.timeZone = TimeZone(secondsFromGMT: 0)
        var template = "MM.dd.yyyy"
        if Calendar.current.component(.year, from: self) < 1910 {
            template = "MM.dd"
        }
        dateFormatter.dateFormat = DateFormatter.dateFormat(fromTemplate: template, options: 0, locale: Locale.current)
        return dateFormatter.string(from: self)
    }
    
}
