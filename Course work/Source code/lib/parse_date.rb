# Parses date and some data
class DateParser
  def time_array(date)
    ar = []
    0.upto(2) do |i|
      ar[i] = date[0..date.index(".").to_i - 1]
      date = date[(date.index(".").to_i + 1)..date.size]
    end
    ar
  end

  def initialize(date)
    ar = time_array(date)
    @day = ar[0].to_i
    @month = ar[1].to_i
    @year = ar[2].to_i
  end

  def self.month_difference(date_end, date_start)
    difference = date_end.month - date_start.month
    month_diff = difference.negative? ? difference + 12 : difference
    month_diff -= 1 if difference.negative?
    month_diff
  end

  def self.day_difference(date_end, date_start)
    day_diff = if (date_end.day - date_start.day).negative?
                 date_end.day - date_start.day + 30
               else
                 date_end.day - date_start.day
               end
    day_diff
  end

  def self.month_str(month_diff)
    month_diff_str = case month_diff
                     when 1
                       "1 месяц"
                     when 2..4
                       month_diff.to_s + " месяца"
                     else
                       month_diff.to_s + " месяцев"
                     end
    month_diff_str
  end

  def self.day_diff(day_diff)
    day_diff_str = case day_diff
                   when 1
                     "1 день"
                   when 2..4
                     day_diff.to_s + " дня"
                   else
                     day_diff.to_s + " дней"
                   end
    day_diff_str
  end

  def self.difference(date_end, date_start)
    month_diff = month_difference(date_end, date_start)
    day_diff = day_difference(date_end, date_start)
    month_diff_str = month_str(month_diff)
    day_diff_str = day_diff(day_diff)
    if month_diff.zero?
      "На всё про всё у нас *#{day_diff_str}*"
    elsif day_diff.zero?
      "На всё про всё у нас *#{month_diff_str}*"
    else "На всё про всё у нас *#{month_diff_str}* и *#{day_diff_str}*"
    end
  end

  def self.get_time_ar(date)
    time_ar = []
    0.upto(2) do |i|
      time_ar[i] = date[0..date.index(".").to_i - 1]
      date = date[(date.index(".").to_i + 1)..date.size]
    end
    time_ar
  end

  def self.get_date(date)
    time_ar = get_time_ar(date)
    day = time_ar[0].to_i
    month = time_ar[1].to_i
    year = time_ar[2].to_i
    [day, month, year]
  end

  def self.get_check(day, month, year, date)
    !(1..31).cover?(day) || !(1..12).cover?(month) || (Time.now.year - year).abs > 1 || (date =~ /\d\d.\d\d.\d\d\d\d$/).nil? || date.index(".").nil?
  end

  def self.correct?(date)
    if date.index(".").nil? then return false end
    day, month, year = get_date(date)
    status = get_check(day, month, year, date) ? false : true

    status
  end

  def self.correct_count?(labs_count)
    check = labs_count.to_i <= 0 || labs_count.to_i > 25
    status = check ? false : true
    status
  end
  attr_accessor :day
  attr_accessor :month
  attr_accessor :year
end
