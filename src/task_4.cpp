import java.util.HashMap;

public class TinyUrlEncoderDecoder {
    private HashMap<String, String> longToShort;
    private HashMap<String, String> shortToLong;
    private static int counter;

    public TinyUrlEncoderDecoder() {
        this.longToShort = new HashMap<>();
        this.shortToLong = new HashMap<>();
        this.counter = 0;
    }

    public String encode(String longUrl) {
        String shortUrl = "http://tinyurl.com/" + counter++;
        longToShort.put(longUrl, shortUrl);
        shortToLong.put(shortUrl, longUrl);
        return shortUrl;
    }

    public String decode(String shortUrl) {
        return shortToLong.getOrDefault(shortUrl, "Short URL not found");
    }

    public static void main(String[] args) {
        TinyUrlEncoderDecoder encoderDecoder = new TinyUrlEncoderDecoder();
        String longUrl = "https://newuu.uz/en/education/school-of-computing";

        String shortUrl = encoderDecoder.encode(longUrl);
        System.out.println("Encoded URL: " + shortUrl);

        String decodedUrl = encoderDecoder.decode(shortUrl);
        System.out.println("Decoded URL: " + decodedUrl);
    }
}
