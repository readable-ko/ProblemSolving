SELECT MEMBER_NAME, REVIEW_TEXT, DATE_FORMAT(REVIEW_DATE, '%Y-%m-%d') as REVIEW_DATE
FROM MEMBER_PROFILE JOIN REST_REVIEW ON MEMBER_PROFILE.MEMBER_ID = REST_REVIEW.MEMBER_ID
WHERE MEMBER_PROFILE.MEMBER_ID = (
    SELECT MP.MEMBER_ID
    FROM MEMBER_PROFILE AS MP JOIN REST_REVIEW AS RR ON MP.MEMBER_ID = RR.MEMBER_ID
    GROUP BY MP.MEMBER_ID
    ORDER BY COUNT(REVIEW_ID) DESC
    LIMIT 1
    )
ORDER BY REVIEW_DATE, REVIEW_TEXT ;